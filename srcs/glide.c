/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:16:12 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/10 10:02:26 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	glide(t_player *player, t_data *data, int new_x, int new_y)
{
	if (!player_is_hiting_a_wall(&data->map, new_x, player->y))
		player->x = new_x;
	else if (!player_is_hiting_a_wall(&data->map, player->x, new_y))
		player->y = new_y;
}

int	glide_x(t_player *player, t_data *data, int new_x)
{	
	if (!player_is_hiting_a_wall(&data->map, new_x, player->y)
		&& player->rotation_angle >= PI
		&& player->rotation_angle < (3 * PI) / 2)
		player->x = new_x;
	else if (!player_is_hiting_a_wall(&data->map, new_x, player->y)
		&& player->rotation_angle >= (3 * PI) / 2
		&& player->rotation_angle < (2 * PI))
		player->x = new_x;
	else if (!player_is_hiting_a_wall(&data->map, new_x, player->y)
		&& player->rotation_angle >= 0 && player->rotation_angle < (PI / 2))
		player->x = new_x;
	else if (!player_is_hiting_a_wall(&data->map, new_x, player->y)
		&& player->rotation_angle >= (PI / 2)
		&& player->rotation_angle < PI)
		player->x = new_x;
	if (player->x == new_x)
		return (0);
	return (-1);
}

void	glide_y(t_player *player, t_data *data, int new_y)
{	
	if (!player_is_hiting_a_wall(&data->map, player->x, new_y)
		&& player->rotation_angle >= PI
		&& player->rotation_angle < (3 * PI) / 2)
		player->y = new_y;
	else if (!player_is_hiting_a_wall(&data->map, player->x, new_y)
		&& player->rotation_angle >= (3 * PI) / 2
		&& player->rotation_angle < (2 * PI))
		player->y = new_y;
	else if (!player_is_hiting_a_wall(&data->map, player->x, new_y)
		&& player->rotation_angle >= 0
		&& player->rotation_angle < (PI / 2))
		player->y = new_y;
	else if (!player_is_hiting_a_wall(&data->map, player->x, new_y)
		&& player->rotation_angle >= (PI / 2)
		&& player->rotation_angle < PI)
		player->y = new_y;
}
