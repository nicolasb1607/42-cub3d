/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:15:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/22 16:28:16 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_prgm.h"

int	launch_prgm(char *file_name)
{
	t_file	file;
	t_data	*data;

	// init_t_file(&file, file_name);

	file.name = file_name;
	file.map_index = 0;
	file.fd = -1;
	data = set_parameters(&file);
	if (!data || !check_map(data->map))
	{
		free_map(data->map, data->map->height);
		free_texture(&data->texture);
		free(data);
		return (1);
	}
	else
	{
		print_2d_array(data->map->content);
		free_map(data->map, data->map->height);
		free_texture(&data->texture);
		free(data);
		return (0);
	}
}
