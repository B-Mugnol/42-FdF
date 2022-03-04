/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:51:33 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/04 01:24:33 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arg_error(const char *err_location, const char *description)
{
	ft_printf("%s: %s\n", err_location, strerror(EINVAL));
	ft_putstr_fd((char *)(description), 1);
	ft_putendl_fd("\nCorrect usage example: ./fdf map_name.fdf", 1);
	return (1);
}

t_data	mlx_error(t_data *data, const char *err_location,
		const char *description)
{
	ft_printf("%s: %s\n", err_location, strerror(ECANCELED));
	ft_putendl_fd((char *)(description), 1);
	data->is_valid = 0;
	return (*data);
}

void	fd_error(const char *err_location, const char *description)
{
	ft_printf("%s: %s\n", err_location, strerror(EBADF));
	ft_putendl_fd((char *)(description), 1);
}
