/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:11:36 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/26 18:46:59 by bmugnol-         ###   ########.fr       */
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

void	translate_point(t_point *pt, double scale_factor, t_point max,
	t_point min)
{
	double	x_translation;
	double	y_translation;

	if ((max.x - min.x) / WINDOW_WIDTH >= (max.y - min.y) / WINDOW_HEIGHT)
	{
		x_translation = 0.5 * (1 - WINDOW_COVERAGE) * WINDOW_WIDTH;
		y_translation = 0.5 * (WINDOW_HEIGHT - (max.y - min.y) * scale_factor);
	}
	else
	{
		x_translation = 0.5 * (WINDOW_WIDTH - (max.x - min.x) * scale_factor);
		y_translation = 0.5 * (1 - WINDOW_COVERAGE) * WINDOW_HEIGHT;
	}
	if (min.x < 0)
		x_translation += -min.x * scale_factor ;
	if (min.y < 0)
		y_translation += -min.y * scale_factor ;
	pt->x += x_translation;
	pt->y += y_translation;
}
