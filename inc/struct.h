/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:24:23 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/05 19:29:27 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_rot
{
	double	x_rot;
	double	y_rot;
	double	z_rot;
}	t_rot;

typedef struct s_map {
	char	**str_map;
	t_point	**base_map;
	t_point	**projection;
	double	z_scale;
	double	scale_factor;
	double	window_coverage;
	int		lines;
	int		columns;
	double	x_translation;
	double	y_translation;
	t_rot	rotation;
	t_point	max;
	t_point	min;
}	t_map;

typedef struct s_image {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_image;

typedef struct s_data {
	char	*filename;
	void	*mlx;
	void	*win;
	t_image	image;
	t_map	map;
	int		is_valid;
}	t_data;

#endif
