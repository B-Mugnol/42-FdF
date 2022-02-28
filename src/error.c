/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:51:33 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/24 21:07:05 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arg_error(const char *err_location, const char *description)
{
	errno = EINVAL;
	perror(err_location);
	ft_putstr_fd((char *)(description), 1);
	ft_putendl_fd("\nCorrect usage example:\t./fdf map_name.fdf", 1);
	return (1);
}

t_data	mlx_error(t_data *data)
{
	ft_putendl_fd("Mlx setup failed.", 1);
	data->is_valid = 0;
	return (*data);
}

void	fd_error(const char *err_location, const char *description)
{
	errno = EBADF;
	perror(err_location);
	ft_putendl_fd((char *)(description), 1);
}
