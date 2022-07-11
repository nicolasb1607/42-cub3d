/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:16:12 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/11 10:58:46 by rpottier         ###   ########.fr       */
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
