/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:22:26 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/26 21:59:48 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_background(t_image *image);

t_data	mount_mlx(char *filename)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (mlx_error(&data));
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, filename);
	if (!data.win)
		return (mlx_error(&data));
	data.image.mlx_img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data.image.mlx_img)
		return (mlx_error(&data));
	data.image.addr = mlx_get_data_addr(data.image.mlx_img, &(data.image.bpp),
			&(data.image.line_size), &(data.image.endian));
	data.is_valid = 1;
	draw_background(&data.image);
	return (data);
}

int	dismount_mlx(t_data *data)
{
	ft_putstr_fd("Clearing Minilibx assets... ", 1);
	mlx_clear_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	mlx_destroy_image(data->mlx, data->image.mlx_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_putendl_fd("Minilibx assets cleared.", 1);
	return (1);
}

static void	draw_background(t_image *image)
{
	char	*pixel;
	size_t	i;

	pixel = image->addr;
	i = 0;
	while (i < (size_t)(WINDOW_HEIGHT) * image->line_size)
		*(pixel + i++) = 0xFF;
}

t_map	map_init(void)
{
	t_map	map;
	t_rot	r;
	t_point	pt;

	map.str_map = NULL;
	map.base_map = NULL;
	map.projection = NULL;
	map.z_scale = 1;
	map.scale_factor = 1;
	map.window_coverage = .8;
	map.lines = 0;
	map.columns = 0;
	r.x_rot = 54.74 * DEG_TO_RAD;
	r.y_rot = 0 * DEG_TO_RAD;
	r.z_rot = 45 * DEG_TO_RAD;
	map.rotation = r;
	pt.z = 0;
	pt.x = WINDOW_WIDTH;
	pt.y = WINDOW_HEIGHT;
	map.min = pt;
	pt.x = -WINDOW_WIDTH;
	pt.y = -WINDOW_HEIGHT;
	map.max = pt;
	return (map);
}

int	map_clear(t_map *map)
{
	t_rot	r;
	t_point	pt;

	ft_putstr_fd("Clearing map... " , 1);
	if (map->str_map)
		ft_free_matrix((void *)(&map->str_map), map->lines);
	if (map->base_map)
		ft_free_matrix((void *)(&map->base_map), map->lines);
	if (map->projection)
		ft_free_matrix((void *)(&map->projection), map->lines);
	map->z_scale = 1;
	map->scale_factor = 1;
	map->lines = 0;
	map->columns = 0;
	r.x_rot = 54.74 * DEG_TO_RAD;
	r.y_rot = 0 * DEG_TO_RAD;
	r.z_rot = 45 * DEG_TO_RAD;
	map->rotation = r;
	pt.z = 0;
	pt.x = WINDOW_WIDTH;
	pt.y = WINDOW_HEIGHT;
	map->min = pt;
	pt.x = -WINDOW_WIDTH;
	pt.y = -WINDOW_HEIGHT;
	map->max = pt;
	ft_putendl_fd("Map cleared." , 1);
}
