/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:09:27 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/12 00:16:05 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_columns(char **str_matrix);

t_map	read_map(char *filename)
{
	int		fd;
	char	*line;
	char	*temp;
	t_map	map;

	fd = open(filename, O_RDONLY);
	temp = ft_strdup("");
	line = get_next_line(fd);
	map.y_max = -1;
	while (line)
	{
		map.y_max++;
		temp = ft_strmerge(temp, line);
		line = get_next_line(fd);
	}
	free(line);
	map.str_map = ft_split(temp, '\n');
	free(temp);
	return (map);
}

int	**evaluate_map(t_map *map)
{
	char	**temp_line;
	int		i;
	int		j;

	i = 0;
	map->int_map = malloc((map->y_max + 2) * sizeof (int *));
	while (i <= map->y_max)
	{
		temp_line = ft_split(map->str_map[i], ' ');
		map->x_max = count_columns(temp_line) - 1;
		j = 0;
		map->int_map[i] = malloc((map->x_max + 1) * sizeof (int));
		while (temp_line[j])
		{
			map->int_map[i][j] = ft_atoi(temp_line[j]);
			j++;
		}
		ft_free_matrix((void *)(&temp_line), map->y_max + 1);
		i++;
	}
	map->int_map[i] = NULL;
	return (map->int_map);
}

static int	count_columns(char **str_matrix)
{
	int	i;

	i = 0;
	while (str_matrix[i] != NULL)
		i++;
	return (i);
}
