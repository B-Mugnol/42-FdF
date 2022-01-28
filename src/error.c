/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:51:33 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/01/28 19:16:39 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arg_error(char *err_msg, char *description)
{
	errno = EINVAL;
	perror(err_msg);
	ft_putstr_fd(description, 1);
	ft_putendl_fd("\nCorrect usage example:\t./fdf mapname.fdf", 1);
	return (0);
}
