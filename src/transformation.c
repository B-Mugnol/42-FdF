/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:11:36 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/05 19:28:38 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Rotation order around axis is as follows: z-axis, x-axis, y-axis.
void	rotate_point(t_point *pt, t_rot r)
{
	t_point	old_pt;

	old_pt = *pt;
	pt->x = old_pt.x * (cos(r.y_rot) * cos(r.z_rot)
			+ sin(r.x_rot) * sin(r.y_rot) * sin(r.z_rot))
		+ old_pt.y * (sin(r.x_rot) * sin(r.y_rot) * cos(r.z_rot)
			- sin(r.z_rot) * cos(r.y_rot))
		+ old_pt.z * cos(r.x_rot) * sin(r.y_rot);
	pt->y = old_pt.x * cos(r.x_rot) * sin(r.z_rot)
		+ old_pt.y * cos(r.x_rot) * cos(r.z_rot)
		- old_pt.z * sin(r.x_rot);
	pt->z = old_pt.x * (sin(r.x_rot) * cos(r.y_rot) * sin(r.z_rot)
			- sin(r.y_rot) * cos(r.z_rot))
		+ old_pt.y * (sin(r.z_rot) * sin(r.y_rot)
			+ sin(r.x_rot) * cos(r.y_rot) * cos(r.z_rot))
		+ old_pt.z * cos(r.x_rot) * cos(r.y_rot);
}

void	scale_point(t_point *pt, double scale_factor)
{
	pt->x = scale_factor * pt->x;
	pt->y = scale_factor * pt->y;
	pt->z = scale_factor * pt->z;
}

void	translate_point(t_point *pt, t_map map)
{
	double	x_translation;
	double	y_translation;

	if ((map.max.x - map.min.x) / WINDOW_WIDTH >= (map.max.y - map.min.y)
		/ WINDOW_HEIGHT)
	{
		x_translation = 0.5 * (1 - map.window_coverage) * WINDOW_WIDTH;
		y_translation = 0.5 * (WINDOW_HEIGHT - (map.max.y - map.min.y)
				* map.scale_factor);
	}
	else
	{
		x_translation = 0.5 * (WINDOW_WIDTH - (map.max.x - map.min.x)
				* map.scale_factor);
		y_translation = 0.5 * (1 - map.window_coverage) * WINDOW_HEIGHT;
	}
	if (map.min.x < 0)
		x_translation += -map.min.x * map.scale_factor;
	if (map.min.y < 0)
		y_translation += -map.min.y * map.scale_factor;
	pt->x += x_translation + map.x_translation;
	pt->y += y_translation + map.y_translation;
}

t_point	get_point(int x, int y, char *str_z)
{
	t_point	pt;
	char	*color_str;

	pt.x = (double)(x);
	pt.y = (double)(y);
	pt.z = (double)(ft_atoi(str_z));
	color_str = ft_strchr(str_z, 'x');
	if (color_str)
	{
		pt.color = ft_atoi_base(color_str + 1, "0123456789abcedf");
		if (pt.color == 0)
			pt.color = ft_atoi_base(color_str + 1, "0123456789ABCDEF");
	}
	else
		pt.color = DEFAULT_COLOR;
	return (pt);
}
