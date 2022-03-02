/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:22:26 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/02 18:14:02 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	mount_mlx(char *filename)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (mlx_error(&data, "mlx_init", "Mlx setup failed."));
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, filename);
	if (!data.win)
		return (mlx_error(&data, "mlx_new_window", "Mlx setup failed."));
	data.image.mlx_img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data.image.mlx_img)
		return (mlx_error(&data, "mlx_new_image", "Mlx setup failed."));
	data.image.addr = mlx_get_data_addr(data.image.mlx_img, &(data.image.bpp),
			&(data.image.line_size), &(data.image.endian));
	data.filename = filename;
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

void	draw_background(t_image *image)
{
	char	*pixel;
	size_t	i;

	pixel = image->addr;
	i = 0;
	while (i < (size_t)(WINDOW_HEIGHT) * image->line_size)
		*(pixel + i++) = 0x00;
}

t_map	map_init(void)
{
	t_map	map;
	t_rot	r;

	map.str_map = NULL;
	map.base_map = NULL;
	map.projection = NULL;
	map.z_scale = 1;
	map.scale_factor = 1;
	map.window_coverage = .8;
	map.lines = 0;
	map.columns = 0;
	map.x_translation = 0;
	map.y_translation = 0;
	r.x_rot = 54.74 * DEG_TO_RAD;
	r.y_rot = 0 * DEG_TO_RAD;
	r.z_rot = 45 * DEG_TO_RAD;
	map.rotation = r;
	map.min = get_point(WINDOW_WIDTH, WINDOW_HEIGHT, "0");
	map.max = get_point(-WINDOW_WIDTH, -WINDOW_HEIGHT, "0");
	return (map);
}

int	map_clear(t_map *map)
{
	t_rot	r;

	ft_putstr_fd("Clearing map... ", 1);
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
	map->x_translation = 0;
	map->y_translation = 0;
	r.x_rot = 54.74 * DEG_TO_RAD;
	r.y_rot = 0 * DEG_TO_RAD;
	r.z_rot = 45 * DEG_TO_RAD;
	map->rotation = r;
	map->min = get_point(WINDOW_WIDTH, WINDOW_HEIGHT, "0");
	map->max = get_point(-WINDOW_WIDTH, -WINDOW_HEIGHT, "0");
	ft_putendl_fd("Map cleared.", 1);
	return (1);
}
