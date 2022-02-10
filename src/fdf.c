/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:27:34 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/10 19:11:38 by bmugnol-         ###   ########.fr       */
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
		return (dismount_mlx(&data));
	mlx_hook(data.win, X_KEY_PRESS_EVENT, X_KEY_PRESS_MASK, &key_press_hook, &data);
	mlx_loop(data.mlx);
	dismount_mlx(&data);
	return (1);
}
