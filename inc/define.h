/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:21:41 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/05 20:28:24 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// Screen size
# define WINDOW_WIDTH	1080
# define WINDOW_HEIGHT	720

// Image-window ratio (on image's largest dimension)
# define DEFAULT_WINDOW_COVERAGE 0.8

// Constant to transform radians into degrees (PI / 180)
# define DEG_TO_RAD		0.017453

// Default color value (gray)
# define DEFAULT_COLOR	0x808080

// String of all digits (in crescent order) of a hexadecimal base
# define HEXA_LOWERCASE_BASE	"0123456789abcedf"
# define HEXA_UPPERCASE_BASE	"0123456789ABCDEF"

// X11 used event codes and their masks
# define X_KEY_PRESS_EVENT	02
# define X_KEY_PRESS_MASK	1L

# define X_DESTROY_NOTIFY_EVENT	17
# define X_DESTROY_NOTIFY_MASK	131072

// Keypress values
# define UP_ARROW_KEY		65362
# define DOWN_ARROW_KEY		65364
# define LEFT_ARROW_KEY		65361
# define RIGHT_ARROW_KEY	65363

# define KEY_ESC			65307
# define KEY_PLUS			61
# define KEY_MINUS			45
# define KEY_PLUS_NUMPAD	65451
# define KEY_MINUS_NUMPAD	65453
# define KEY_PAGE_UP		65365
# define KEY_PAGE_DOWN		65366

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

#endif
