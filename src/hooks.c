/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:19:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/02 19:28:45 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	wasd_key_press(int keycode, t_data *data);
static void	arrow_key_press(int keycode, t_data *data);

int	mouse_hook(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (1);
}

int	key_press_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(data->mlx);
		return (1);
	}
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		wasd_key_press(keycode, data);
	if (keycode == UP_ARROW_KEY || keycode == DOWN_ARROW_KEY
		|| keycode == LEFT_ARROW_KEY || keycode == RIGHT_ARROW_KEY)
		arrow_key_press(keycode, data);
	if (keycode == KEY_PLUS || keycode == KEY_PLUS_NUMPAD)
		data->map.window_coverage += 0.1;
	if (keycode == KEY_MINUS || keycode == KEY_MINUS_NUMPAD)
		data->map.window_coverage -= 0.1;
	if (keycode == KEY_Q)
		data->map.z_scale -= 0.1;
	if (keycode == KEY_E)
		data->map.z_scale += 0.1;
	map_controller(data->filename, &(data->map), 0);
	mlx_controller(data, &(data->map), 0);
	return (1);
}

static void	wasd_key_press(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->map.rotation.x_rot -= 17.63 * DEG_TO_RAD;
	if (keycode == KEY_S)
		data->map.rotation.x_rot += 17.63 * DEG_TO_RAD;
	if (keycode == KEY_A)
		data->map.rotation.z_rot -= 15 * DEG_TO_RAD;
	if (keycode == KEY_D)
		data->map.rotation.z_rot += 15 * DEG_TO_RAD;
}

static void	arrow_key_press(int keycode, t_data *data)
{
	if (keycode == UP_ARROW_KEY)
		data->map.y_translation -= 0.05 * WINDOW_HEIGHT;
	if (keycode == DOWN_ARROW_KEY)
		data->map.y_translation += 0.05 * WINDOW_HEIGHT;
	if (keycode == LEFT_ARROW_KEY)
		data->map.x_translation -= 0.05 * WINDOW_HEIGHT;
	if (keycode == RIGHT_ARROW_KEY)
		data->map.x_translation += 0.05 * WINDOW_HEIGHT;
}
