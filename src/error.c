/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:51:33 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/02 18:13:21 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arg_error(const char *err_location, const char *description)
{
	int	errsv;

	errno = EINVAL;
	errsv = errno;
	perror(err_location);
	ft_putstr_fd((char *)(description), 1);
	ft_putendl_fd("\nCorrect usage example:\t./fdf map_name.fdf", 1);
	errno = errsv;
	return (1);
}

t_data	mlx_error(t_data *data, const char *err_location,
		const char *description)
{
	int	errsv;

	errno = ECANCELED;
	errsv = errno;
	perror(err_location);
	ft_putendl_fd((char *)(description), 1);
	data->is_valid = 0;
	errno = errsv;
	return (*data);
}

void	fd_error(const char *err_location, const char *description)
{
	int	errsv;

	errno = EBADF;
	errsv = errno;
	perror(err_location);
	ft_putendl_fd((char *)(description), 1);
	errno = errsv;
}
