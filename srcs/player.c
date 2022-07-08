/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:09:30 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 14:11:54 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "player.h"


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

void	refactor_angle(double *angle)
{
	if (*angle < 0)
		*angle += (2 * PI);
	*angle = fmod(*angle, PI * 2);	
}

int	glide_x(t_player *player, t_data *data, int new_x)
{	
	if (!player_is_hiting_a_wall(&data->map, new_x, player->y) && player->rotation_angle >= PI && player->rotation_angle < (3*PI)/2)
	{
		player->x =  new_x;
		return (0);
	}
	else if (!player_is_hiting_a_wall(&data->map, new_x, player->y) && player->rotation_angle >= (3*PI)/2 && player->rotation_angle < (2 * PI))
	{
			player->x =  new_x;
			return (0);
	}
	else if (!player_is_hiting_a_wall(&data->map, new_x, player->y) && player->rotation_angle >= 0 && player->rotation_angle < ((PI/2)))
	{
		player->x =  new_x;
		return (0);
	}
	else if (!player_is_hiting_a_wall(&data->map, new_x , player->y) && player->rotation_angle >= (PI/2) && player->rotation_angle < PI)
	{
		player->x = new_x;
		return (0);
	}
	return (-1);
}

void	glide_y(t_player *player, t_data *data, int new_y)
{	
	if (!player_is_hiting_a_wall(&data->map, player->x, new_y) && player->rotation_angle >= PI && player->rotation_angle < (3*PI)/2)
		player->y =  new_y;
	else if (!player_is_hiting_a_wall(&data->map, player->x, new_y) && player->rotation_angle >= (3*PI)/2 && player->rotation_angle < (2 * PI))
		player->y =  new_y;
	else if (!player_is_hiting_a_wall(&data->map, player->x, new_y) && player->rotation_angle >= 0 && player->rotation_angle < ((PI/2)))
		player->y =  new_y;
	else if (!player_is_hiting_a_wall(&data->map, player->x, new_y) && player->rotation_angle >= (PI/2) && player->rotation_angle < PI)
		player->y = new_y;
}

void	update_player(t_data *data)
{
//	printf("update_player\n");

	int move_step;
	int new_player_x = 0;
	int new_player_y = 0;

	//SET_UP direction des mouvements

	move_step = (data->player.walk_direction * data->player.walk_speed);
	data->player.rotation_angle = data->player.rotation_angle - (data->player.left_right_rotation * data->player.rotation_speed);
	if (data->player.rotation_angle < 0)
		data->player.rotation_angle += (2 * PI);
	data->player.rotation_angle = fmod(data->player.rotation_angle, 2 * PI);
	//MAJ de la position du joueur
	new_player_x = round(data->player.x + (cos(data->player.rotation_angle + data->player.side_move_angle) * move_step));
	new_player_y = round(data->player.y + (sin(data->player.rotation_angle + data->player.side_move_angle) * move_step));	
	if (!player_is_hiting_a_wall(&data->map, new_player_x, new_player_y))
	{
		data->player.x= new_player_x;
		data->player.y = new_player_y;
	}
	else if (data->player.walk_direction == 1 && data->player.side_move_angle == 0)
	{
		if (glide_x(&data->player, data, new_player_x) == -1)
			glide_y(&data->player, data, new_player_y);
	}	
	//Remise à zéro des variables de mouvements
	data->player.left_right_rotation = 0;
	data->player.walk_direction = 0;
	data->player.side_move_angle = 0;
}

