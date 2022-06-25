/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:25:19 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/24 19:43:16 by nburat-d         ###   ########.fr       */
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
	return (data);
}
