/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:54:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/05 17:13:47 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapping.h"

int	is_hiting_a_wall(t_map *map, int x, int y)
{
	if (x <= 0 || x >= TILE_SIZE * map->width || y <= 0 || y >= TILE_SIZE * map->height)
		return (TRUE);
	if (map->content[y / TILE_SIZE][x / TILE_SIZE] == '1')
		return (TRUE);
	return (FALSE);
}

void	update_player(t_data *data)
{
//	printf("update_player\n");

	int move_step;
	int new_player_x = 0;
	int new_player_y = 0;

	//SET_UP direction des mouvements

	move_step = (data->player->walk_direction * data->player->walk_speed);
	data->player->rotation_angle = data->player->rotation_angle - (data->player->left_right_rotation * data->player->rotation_speed);
	if (data->player->rotation_angle < 0)
		data->player->rotation_angle += (2 * PI);
	data->player->rotation_angle = fmod(data->player->rotation_angle, 2 * PI);
	//MAJ de la position du joueur
	new_player_x = round(data->player->x_pos + (cos(data->player->rotation_angle + data->player->side_move_angle) * move_step));
	new_player_y = round(data->player->y_pos + (sin(data->player->rotation_angle + data->player->side_move_angle) * move_step));
	
	if (!is_hiting_a_wall(data->map, new_player_x, new_player_y))
	{
		data->player->x_pos = new_player_x;
		data->player->y_pos = new_player_y;
	}
	//Remise à zéro des variables de mouvements
	data->player->left_right_rotation = 0;
	data->player->walk_direction = 0;
	data->player->side_move_angle = 0;
}
