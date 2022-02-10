/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:22:26 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/10 19:07:48 by bmugnol-         ###   ########.fr       */
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
	mlx_clear_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	mlx_destroy_image(data->mlx, data->image.mlx_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
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
