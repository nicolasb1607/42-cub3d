/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:25:19 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/07 13:53:56 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"





t_data	*set_parameters(t_file	*file)
{
	t_data	*data;

	file->fd = open(file->name, O_RDONLY);
	if (file->fd == -1)
		return (ft_putstr_fd(ERROR_OPEN_FILE, 2), NULL);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (close(file->fd), NULL);
	data->texture = set_texture(file);
	if (!data->texture)
		return (free(data), NULL);
	data->map = set_map(file);
	close(file->fd);
	if (!data->map)
		return (free(data->texture), free(data), NULL);
	if (set_color(data) != 0)
		return (free_map(data->map, data->map->height),
			free_texture(&data->texture), free(data), NULL);
//	set_player(data);
	data->player = set_player(data->map);
	if (!data->player)
		return (free_map(data->map, data->map->height), free_texture(&data->texture), free(data), NULL);
	return (data);
}

double	get_start_angle(char c)
{
	if (c == 'E')
		return (0);
	else if (c == 'S')
		return (PI / 2);
	else if (c == 'W')
		return (PI);
	else if (c == 'N')
		return ((3 * PI) / 2);
	return (0);
}
/*
void	set_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (is_a_player(data->map->content[i][j]))
			{
				data->player.x_pos = (j * TILE_SIZE) + (TILE_SIZE / 2);
				data->player.y_pos = (i * TILE_SIZE) + (TILE_SIZE / 2);
				data->player.rotation_angle = get_start_angle(data->map->content[i][j]);
			}
			j++;
		}
		i++;
	}
	data->player.width = 1;
	data->player.height = 1;
	data->player.left_right_rotation = 0;
	data->player.walk_direction = 0;
	data->player.side_move_angle = 0;
	data->player.walk_speed = WALK_SPEED;
	data->player.rotation_speed = ROTATION_SPEED;
//	return (player);
}
*/


t_player *set_player(t_map *map)
{
	int	i;
	int	j;
	t_player *player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (is_a_player(map->content[i][j]))
			{
				player->x_pos = (j * TILE_SIZE) + (TILE_SIZE / 2);
				player->y_pos = (i * TILE_SIZE) + (TILE_SIZE / 2);
				player->rotation_angle = get_start_angle(map->content[i][j]);
			}
			j++;
		}
		i++;
	}
	player->width = 1;
	player->height = 1;
	player->left_right_rotation = 0;
	player->walk_direction = 0;
	player->side_move_angle = 0;
	player->walk_speed = WALK_SPEED;
	player->rotation_speed = ROTATION_SPEED;
	return (player);
}
