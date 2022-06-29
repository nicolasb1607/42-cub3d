/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:25:19 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/29 09:34:09 by rpottier         ###   ########.fr       */
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
		return (free(data->ceiling_color), free(data->floor_color), free_map(data->map, data->map->height),
			free_texture(&data->texture), free(data), NULL);
	return (data);
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
			}
			j++;
		}
		i++;
	}
	player->width = 1;
	player->height = 1;
	player->turn_direction = 0;
	player->walk_direction = 0;
//	player->rotation_walk_side
	player->rotation_angle = PI / 2; // Determiner angle de depart en fonction de la lettre trouvee dans la map E = 0; S = PI / 2; W = PI; N = (3*PI) / 2
	player->walk_speed = 2.0;
	player->turn_speed = 4 * (PI / 180);
	return (player);
}