/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:27:34 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/02 20:31:33 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	rerender(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	data;
	t_map	map;

	if (param_verifier(argc, argv[1]))
		return (0);
	data.filename = argv[1];
	if (!map_controller(data.filename, &map, 1))
		return (map_controller(data.filename, &map, -1));
	ft_putendl_fd("\nUse WASD to rotate camera angle,\
	 	\nArrow keys to move the camera around,\
		\nand QE to decrease or increase the height scale.", 1);
	mlx_controller(&data, &map, 1);
	map_controller(data.filename, &map, -1);
	ft_putendl_fd("Program terminated succesfully.", 1);
	return (1);
}

int	map_controller(char *filename, t_map *map, int init)
{
	int		fd;

	if (init == 1)
	{
		*map = map_init();
		fd = open(filename, O_RDONLY);
		if (fd_verifier(fd))
			return (0);
		read_map(fd, map);
		close(fd);
		get_base_map(map);
		project_map(map, init);
		scale_map(map);
	}
	else if (init == 0)
	{
		map->min = get_point(WINDOW_WIDTH, WINDOW_HEIGHT, "0");
		map->max = get_point(-WINDOW_WIDTH, -WINDOW_HEIGHT, "0");
		project_map(map, init);
		scale_map(map);
	}
	else
		map_clear(map);
	return (1);
}

int	mlx_controller(t_data *data, t_map *map, int init)
{
	if (init == 1)
	{
		*data = mount_mlx(data->filename);
		if (data_verifier(data))
			return (0);
		data->map = *map;
		ft_putendl_fd("Rendering map...", 1);
		draw_map(data->image, data->map);
		mlx_put_image_to_window(data->mlx, data->win, data->image.mlx_img,
			0, 0);
		mlx_hook(data->win, X_KEY_PRESS_EVENT, X_KEY_PRESS_MASK,
			&key_press_hook, data);
		mlx_hook(data->win, X_DESTROY_NOTIFY_EVENT, X_DESTROY_NOTIFY_MASK,
			&mouse_hook, data);
		mlx_expose_hook(data->win, &rerender, data);
		mlx_loop(data->mlx);
		dismount_mlx(data);
		return (1);
	}
	draw_background(&(data->image));
	draw_map(data->image, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->image.mlx_img,
		0, 0);
	return (1);
}

static int	rerender(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->image.mlx_img, 0, 0);
	return (1);
}
