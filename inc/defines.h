/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:21:41 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/04 01:27:52 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

// Constant to transform radians into degrees (PI / 180)
# define DEG_TO_RAD		0.017453

// Default color value (gray)
# define DEFAULT_COLOR	0x808080

// Screen size
# define WINDOW_WIDTH	1080
# define WINDOW_HEIGHT	720

// Image-window ratio (on image's largest dimension)
# define DEFAULT_WINDOW_COVERAGE 0.8

// X11 used event codes and their masks
# define X_KEY_PRESS_EVENT	02
# define X_KEY_PRESS_MASK	1L

# define X_DESTROY_NOTIFY_EVENT	17
# define X_DESTROY_NOTIFY_MASK	131072

// Keypress values
# define UP_ARROW_KEY		65362
# define LEFT_ARROW_KEY		65361
# define DOWN_ARROW_KEY		65364
# define RIGHT_ARROW_KEY	65363

# define KEY_ESC			65307
# define KEY_PLUS			61
# define KEY_MINUS			45
# define KEY_PLUS_NUMPAD	65451
# define KEY_MINUS_NUMPAD	65453

# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100
# define KEY_Q	113
# define KEY_E	101

// Error codes (values used as defined in <errno.h>)
# ifndef EBADF
#  define EBADF		9
# endif
# ifndef EINVAL
#  define EINVAL	22
# endif
# ifndef ECANCELED
#  define ECANCELED	125
# endif

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
