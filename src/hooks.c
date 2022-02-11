/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:19:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/11 23:34:17 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(data->mlx);
		return (1);
	}
	return (0);
}
