/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:03:39 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/28 22:27:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_dabs(double n);
static void		ft_swap(double *a, double *b);
static void		plot_low_slope_line(t_image image, t_point p0, t_point p1);
static void		plot_high_slope_line(t_image image, t_point p0, t_point p1);

void	draw_line(t_image image, t_point p0, t_point p1)
{
	p0.x = round(p0.x);
	p0.y = round(p0.y);
	p1.x = round(p1.x);
	p1.y = round(p1.y);
	if (p0.color == DEFAULT_COLOR)
		p1.color = DEFAULT_COLOR;
	if (p1.color == DEFAULT_COLOR)
		p0.color = DEFAULT_COLOR;
	if (ft_dabs(p1.x - p0.x) >= ft_dabs(p1.y - p0.y))
		plot_low_slope_line(image, p0, p1);
	else
		plot_high_slope_line(image, p0, p1);
}

static void	plot_low_slope_line(t_image image, t_point p0, t_point p1)
{
	int	delta_x;
	int	delta_y;
	int	diff;
	int	x;
	int	y;

	delta_x = (int)(p1.x - p0.x);
	if (delta_x < 0)
	{
		delta_x = -delta_x;
		ft_swap(&(p1.x), &(p0.x));
		ft_swap(&(p1.y), &(p0.y));
	}
	delta_y = (int)(p1.y - p0.y);
	diff = 2 * ft_dabs(delta_y) - delta_x;
	x = (int)(p0.x);
	y = (int)(p0.y);
	while (x <= (int)(p1.x))
	{
		put_image_pixel(&image, x, y, p0.color);
		if (diff > 0)
			y += (delta_y > 0) - (delta_y < 0);
		diff += 2 * ft_dabs(delta_y) - 2 * delta_x * (diff > 0);
		x++;
	}
}

static void	plot_high_slope_line(t_image image, t_point p0, t_point p1)
{
	int	delta_x;
	int	delta_y;
	int	diff;
	int	x;
	int	y;

	delta_y = (int)(p1.y - p0.y);
	if (delta_y < 0)
	{
		delta_y = -delta_y;
		ft_swap(&(p1.x), &(p0.x));
		ft_swap(&(p1.y), &(p0.y));
	}
	delta_x = (int)(p1.x - p0.x);
	diff = 2 * ft_dabs(delta_x) - delta_y;
	x = (int)(p0.x);
	y = (int)(p0.y);
	while (y <= (int)(p1.y))
	{
		put_image_pixel(&image, x, y, p0.color);
		if (diff > 0)
			x += (delta_x > 0) - (delta_x < 0);
		diff += 2 * ft_dabs(delta_x) - 2 * delta_y * (diff > 0);
		y++;
	}
}

static void	ft_swap(double *a, double *b)
{
	double	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

static double	ft_dabs(double n)
{
	return (n * ((n > 0) - (n < 0)));
}
