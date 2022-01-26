/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:51:36 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/01/26 22:37:43 by bmugnol-         ###   ########.fr       */
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

// checker.c
int	param_checker(int argc);

// error.c
int	arg_error(char *err_msg, char *description);

#endif
