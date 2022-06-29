/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:15:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/29 12:09:47 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_control.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_exit(data);
	if (keycode == XK_z)
	{
		data->player->walk_direction = +1;
		refresh_img(data);
	}
	if (keycode == XK_s)
	{
		data->player->walk_direction = -1;
		refresh_img(data);
	}
	if (keycode == XK_q)
	{
		data->player->walk_direction = -1;
		data->player->side_angle = PI / 2;
		refresh_img(data);
	}
	if (keycode == XK_d)
	{
		data->player->walk_direction = -1;
		data->player->side_angle = -(PI / 2);
		refresh_img(data);
	}
	if (keycode == XK_Right)
	{
		data->player->turn_direction = +1;
		refresh_img(data);
	}
	if (keycode == XK_Left)
	{
		data->player->turn_direction = -1;
		refresh_img(data);
	}
	return (0);
}
