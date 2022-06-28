/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:15:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/28 20:26:39 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_control.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_exit(data);
	if (keycode == XK_Up)
	{
		data->player->walk_direction = +1;
		refresh_img(data);
	}
	if (keycode == XK_Down)
	{
		data->player->walk_direction = -1;
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
