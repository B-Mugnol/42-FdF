/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:51:36 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/05 19:33:16 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"	// Used for ft_printf function
# include "struct.h"// Defines structs used in the program
# include "define.h"// Defines constants used in the program
# include "libft.h"	// Libft
# include <mlx.h>	// Minilibx
# include <math.h>	// C Math library
# include <fcntl.h>	// File control options (used to open file)
# include <string.h>// Defines the 'strerror' function (used for error messages)
# include <unistd.h>// Used for 'write', 'read', and 'close' functions
# include <stdlib.h>// Used for 'malloc' and 'free' functions

// fdf.c
int		map_controller(char *filename, t_map *map, int init);
int		mlx_controller(t_data *data, t_map *map, int init);

// setup.c
t_data	mount_mlx(char *filename);
int		dismount_mlx(t_data *data);
t_map	map_init(void);
int		map_clear(t_map *map);
void	draw_background(t_image *image);

// map.c
void	read_map(int fd, t_map *map);
void	get_base_map(t_map *map);
void	project_map(t_map *map, int init);
void	scale_map(t_map *map);

// render.c
void	put_image_pixel(t_image *image, int x, int y, int color);
void	draw_map(t_image image, t_map map);

// line_draw.c
void	draw_line(t_image image, t_point p0, t_point p1);

// transformation.c
t_point	get_point(int x, int y, char *str_z);
void	rotate_point(t_point *pt, t_rot r);
void	scale_point(t_point *pt, double scale_factor);
void	translate_point(t_point *pt, t_map map);

// hook.c
int		mouse_hook(t_data *data);
int		key_press_hook(int keycode, t_data *data);

// error.c
void	fd_error(const char *err_location, const char *description);
int		arg_error(const char *err_location, const char *description);
t_data	mlx_error(t_data *data, const char *err_location,
			const char *description);

// verifier.c
int		param_verifier(const int argc, const char *map_file);
int		data_verifier(t_data *data);
int		fd_verifier(int fd);

#endif
