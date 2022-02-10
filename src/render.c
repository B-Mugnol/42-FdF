/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:23:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/10 00:29:45 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_image_pixel(t_image *image, int x, int y, int color)
{
	char	*pixel;
	int		i;

	pixel = image->addr + x * (image->bpp / 8) + y * image->line_size;
	i = 0;
	if (image->endian == 1)
	{
		while (image->bpp >= 8 * i)
		{
			*pixel = (color >> (image->bpp - 8 - i * 8)) & 0xFF;
			pixel++;
			i++;
		}
	}
	else
	{
		while (image->bpp >= 8 * i)
		{
			*pixel = (color >> i * 8) & 0xFF;
			pixel++;
			i++;
		}
	}
}
