/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:27:34 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/10 17:55:55 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_data data;

	if (!is_valid_param(argc, argv[1]))
		return (0);
	data = mount_mlx(argv[1]);
	if (!is_valid_data(&data))
		return (0);
	dismount_mlx(&data);
	return (1);
}
