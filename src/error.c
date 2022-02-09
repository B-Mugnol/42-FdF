/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:51:33 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/09 19:14:48 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arg_error(const char *err_msg, const char *description)
{
	errno = EINVAL;
	perror(err_msg);
	ft_putstr_fd((char *)(description), 1);
	ft_putendl_fd("\nCorrect usage example:\t./fdf map_name.fdf", 1);
	return (0);
}

t_data	mlx_error(t_data *data)
{
	ft_putendl_fd("Mlx setup failed.", 1);
	(*data).is_valid = 0;
	return (*data);
}
