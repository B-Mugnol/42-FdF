/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:51:36 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/10 17:55:45 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

# define WINDOW_WIDTH	720
# define WINDOW_HEIGHT	360

typedef struct s_image {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_image;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_image	image;
	int		is_valid;
}	t_data;

typedef struct s_point {
	double	x;
	double	y;
	double	z;
}	t_point;

// error.c
int		arg_error(const char *err_msg, const char *description);
t_data	mlx_error(t_data *data);

// checker.c
int		is_valid_param(const int argc, const char *map_file);
int		is_valid_data(t_data *data);

// setup.c
t_data	mount_mlx(char *filename);
void	dismount_mlx(t_data *data);

// render.c
void	put_image_pixel(t_image *image, int x, int y, int color);

#endif
