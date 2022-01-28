/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:51:33 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/01/28 22:02:23 by bmugnol-         ###   ########.fr       */
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
