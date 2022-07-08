/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:25:19 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 14:57:06 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	open_file(char *file_name, int	*fd)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
	{
		ft_putstr_fd(ERROR_OPEN_FILE, 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	*set_parameters(t_data *data, t_file	*file)
{
	if (!open_file(file->name, &file->fd))
		return (NULL);
	if (!set_texture(&data->texture, file)
		|| !set_map(&data->map, file)
		|| !set_color(data)
		|| !set_player(data))
	{
		close(file->fd);
		ft_exit_status(data, SET_PARAMS_FAILURE);
	}
	close(file->fd);
	if (!init_gui(&data->gui))
		ft_exit_status(data, INIT_GUI_FAILURE);
	if (!load_texture(data))
		ft_exit_status(data, LOAD_TEXTURE_FAILURE);
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

int	set_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (is_a_player(data->map.content[i][j]))
			{
				data->player.x = (j * TILE_SIZE) + (TILE_SIZE / 2);
				data->player.y = (i * TILE_SIZE) + (TILE_SIZE / 2);
				data->player.rotation_angle = get_start_angle
					(data->map.content[i][j]);
			}
			j++;
		}
		i++;
	}
	data->player.walk_speed = WALK_SPEED;
	data->player.rotation_speed = ROTATION_SPEED;
	return (SUCCESS);
}
