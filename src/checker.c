/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:33:41 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/01/26 22:41:34 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	param_checker(int argc)
{
	if (argc < 2)
		return (arg_error("fdf", "Too few arguments."));
	if (argc > 2)
		return (arg_error("fdf", "Too many arguments."));
	return (1);
}
