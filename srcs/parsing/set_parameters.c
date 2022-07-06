/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:25:19 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/06 10:08:53 by rpottier         ###   ########.fr       */
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
		return (NULL);
	data->texture = set_texture(file);
	if (!data->texture)
		return (free(data), NULL);
	data->map = set_map(file);
	if (!data->map)
		return (free(data->texture), free(data), NULL);
	if (set_color(data) != 0)
		return (free_map(data->map, data->map->height),
			free_texture(&data->texture), free(data), NULL);
	data->player = set_player(data->map);
	if (!data->player)
		return (free(data->map->ceiling_color), free(data->map->floor_color), free_map(data->map, data->map->height),
			free_texture(&data->texture), free(data), NULL);
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
