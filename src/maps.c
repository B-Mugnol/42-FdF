/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:09:27 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/26 18:44:40 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	find_constants(t_point pt, t_map *map);
// static void	evaluate_initial_points(t_map *map, char **map_line, int y);

void	read_map(int fd, t_map *map)
{
	char	*line;
	char	*temp;

	ft_putendl_fd("Reading file...", 1);
	temp = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		map->lines++;
		temp = ft_strmerge(temp, line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	map->str_map = ft_split(temp, '\n');
	free(temp);
	return ;
}

void	get_base_map(t_map *map)
{
	t_point	pt;
	char	**line;
	int		x;
	int		y;

	ft_putendl_fd("Processing file content...", 1);
	y = -1;
	map->base_map = malloc(map->lines * sizeof (t_point *));
	while (++y < map->lines)
	{
		line = ft_split(map->str_map[y], ' ');
		if (map->columns == 0)
			while (line[map->columns] != NULL)
				map->columns++;
		map->base_map[y] = malloc(map->columns * sizeof (t_point));
		x = -1;
		while (line[++x])
		{
			pt.x = (double)(x);
			pt.y = (double)(y);
			pt.z = (double)(ft_atoi(line[x]));
			map->base_map[y][x] = pt;
		}
		ft_free_matrix((void *)(&line), map->columns);
	}
	ft_free_matrix((void *)(&map->str_map), map->lines);
}

void	project_map(t_map *map, int init)
{
	t_point	pt;
	int		x;
	int		y;

	ft_putendl_fd("Calculating points...", 1);
	if (init == 1)
		map->projection = malloc(map->lines * sizeof (t_point *));
	y = -1;
	while (++y < map->lines)
	{
		if (init == 1)
			map->projection[y] = malloc(map->columns * sizeof (t_point));
		x = -1;
		while (++x < map->columns)
		{
			pt = map->base_map[y][x];
			pt.z = pt.z * map->z_scale;
			rotate_point(&pt, map->rotation);
			find_constants(pt, map);
			map->projection[y][x] = pt;
		}
	}
}

void	scale_map(t_map *map)
{
	int		x;
	int		y;
	double	delta_x;
	double	delta_y;

	delta_x = map->max.x - map->min.x;
	delta_y = map->max.y - map->min.y;
	if (delta_x / WINDOW_WIDTH >= delta_y / WINDOW_HEIGHT)
		map->scale_factor = WINDOW_COVERAGE * WINDOW_WIDTH / delta_x;
	else
		map->scale_factor = WINDOW_COVERAGE * WINDOW_HEIGHT / delta_y;
	y = 0;
	while (y < map->lines)
	{
		x = 0;
		while (x < map->columns)
		{
			scale_point(&map->projection[y][x], map->scale_factor);
			translate_point(&map->projection[y][x], map->scale_factor,
				map->max, map->min);
			x++;
		}
		y++;
	}
}

static void	find_constants(t_point pt, t_map *map)
{
	if (pt.x <= map->min.x)
		map->min.x = pt.x;
	if (pt.x >= map->max.x)
		map->max.x = pt.x;
	if (pt.y <= map->min.y)
		map->min.y = pt.y;
	if (pt.y >= map->max.y)
		map->max.y = pt.y;
	if (pt.z <= map->min.z)
		map->min.z = pt.z;
	if (pt.z >= map->max.z)
		map->max.z = pt.z;
}
