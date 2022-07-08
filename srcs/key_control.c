/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:15:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 15:07:40 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_control.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_exit_status(data, FREE_ALL);
	if (keycode == XK_z)
		data->player.walk_direction = +1;
	if (keycode == XK_s)
		data->player.walk_direction = -1;
	if (keycode == XK_q)
	{
		data->player.walk_direction = +1;
		data->player.side_move_angle = -(PI / 2);
	}
	if (keycode == XK_d)
	{
		data->player.walk_direction = +1;
		data->player.side_move_angle = PI / 2;
	}
	if (keycode == XK_Right)
		data->player.left_right_rotation = -1;
	if (keycode == XK_Left)
		data->player.left_right_rotation = +1;
	refresh_img(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	(void)key;
	(void)data;
	return (0);
}

void	mlx_setting_loop_hooks(t_data *data)
{
	mlx_hook(data->gui.win, 2, (1L << 0), &key_hook, data);
	mlx_hook(data->gui.win, 3, (1L << 1), &key_release, data);
	mlx_hook(data->gui.win, 17, 0, ft_exit_red_cross, data);
	mlx_loop(data->gui.mlx);
}
