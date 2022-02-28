/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:23:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/28 22:20:52 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_image_pixel(t_image *image, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pixel = image->addr + x * (image->bpp / 8) + y * image->line_size;
	if (image->endian == 0)
	{
		i = 0;
		while (i < image->bpp)
		{
			*pixel++ = (color >> (sizeof(color) * 8 - image->bpp + i)) & 0xFF;
			i += 8;
		}
	}
	else
	{
		i = 8;
		while (i <= image->bpp)
		{
			*pixel++ = (color >> (sizeof(color) * 8 - i)) & 0xFF;
			i += 8;
		}
	}
}

void	draw_map(t_image image, t_map map)
{
	t_point	p1;
	t_point	p2;
	int		x;
	int		y;

	y = -1;
	while (++y < map.lines)
	{
		x = -1;
		while (++x < map.columns)
		{
			p1 = map.projection[y][x];
			if (x < map.columns - 1)
			{
				p2 = map.projection[y][x + 1];
				draw_line(image, p1, p2);
			}
			if (y < map.lines - 1)
			{
				p2 = map.projection[y + 1][x];
				draw_line(image, p1, p2);
			}
		}
	}
}
