/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:54:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/07 15:40:09 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapping.h"

int	ray_is_hiting_a_wall(t_map *map, int x, int y)
{
	if (x <= 0 || x >= TILE_SIZE * map->width || y <= 0 || y >= TILE_SIZE * map->height)
		return (TRUE);
	if (map->content[y / TILE_SIZE][x / TILE_SIZE] == '1')
		return (TRUE);
	return (FALSE);
}

int	player_is_hiting_a_wall(t_map *map, int x, int y)
{
	if (x <= 0 || x >= TILE_SIZE * map->width || y <= 0 || y >= TILE_SIZE * map->height)
		return (TRUE);
	if (map->content[(y - PLAYER_RADIUS)/ TILE_SIZE][x / TILE_SIZE] == '1')
		return (TRUE);
	else if (map->content[(y + PLAYER_RADIUS)/ TILE_SIZE][x / TILE_SIZE] == '1')
		return (TRUE);
	else if (map->content[y / TILE_SIZE][(x - PLAYER_RADIUS) / TILE_SIZE] == '1')
		return (TRUE);
	else if (map->content[y / TILE_SIZE][(x + PLAYER_RADIUS)/ TILE_SIZE] == '1')
		return (TRUE);
	return (FALSE);
}

int	glide_x(t_player *player, t_data *data)
{	
	if (!player_is_hiting_a_wall(data->map, player->x_pos - 10, player->y_pos) && player->rotation_angle > PI && player->rotation_angle < (3*PI)/2)
	{
		player->x_pos -= 10;
		return (0);
	}
	else if (!player_is_hiting_a_wall(data->map, player->x_pos + 10, player->y_pos) && player->rotation_angle > (3*PI)/2 && player->rotation_angle < (2 * PI))
	{
			player->x_pos += 10;
			return (0);
	}
	else if (!player_is_hiting_a_wall(data->map, player->x_pos + 10, player->y_pos) && player->rotation_angle > 0 && player->rotation_angle < ((PI/2)))
	{
		player->x_pos += 1;
		return (0);
	}
	else if (!player_is_hiting_a_wall(data->map, player->x_pos - 10, player->y_pos) && player->rotation_angle > (PI/2) && player->rotation_angle < PI)
	{
		player->x_pos -= 10;
		return (0);
	}
	return (-1);
	
}

void	glide_y(t_player *player, t_data *data)
{	
	if (!player_is_hiting_a_wall(data->map, player->x_pos, player->y_pos - 10) && player->rotation_angle > PI && player->rotation_angle < (3*PI)/2)
		player->y_pos -= 10;
	else if (!player_is_hiting_a_wall(data->map, player->x_pos, player->y_pos + 10) && player->rotation_angle > (3*PI)/2 && player->rotation_angle < (2 * PI))
		player->y_pos -= 10;
	else if (!player_is_hiting_a_wall(data->map, player->x_pos, player->y_pos + 10) && player->rotation_angle > 0 && player->rotation_angle < ((PI/2)))
		player->y_pos += 10;
	else if (!player_is_hiting_a_wall(data->map, player->x_pos, player->y_pos - 10) && player->rotation_angle > (PI/2) && player->rotation_angle < PI)
		player->y_pos += 10;
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
	if (!player_is_hiting_a_wall(data->map, new_player_x, new_player_y))
	{
		data->player->x_pos = new_player_x;
		data->player->y_pos = new_player_y;
	}
	else
	{
		if (glide_x(data->player, data) == -1)
			glide_y(data->player, data);
	}	
	//Remise à zéro des variables de mouvements
	data->player->left_right_rotation = 0;
	data->player->walk_direction = 0;
	data->player->side_move_angle = 0;
}
