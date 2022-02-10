/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:51:36 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/10 18:53:22 by bmugnol-         ###   ########.fr       */
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

// Screen size
# define WINDOW_WIDTH	720
# define WINDOW_HEIGHT	360

// X11 used event codes and their masks
# define X_KEY_PRESS_EVENT	02
# define X_KEY_PRESS_MASK	1L<<0

// Key values
# define KEY_ESC	65307

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
int		dismount_mlx(t_data *data);

// render.c
void	put_image_pixel(t_image *image, int x, int y, int color);

// hooks.c
int	key_press_hook(int keycode, t_data *data);

#endif
