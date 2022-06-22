/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:15:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/22 10:52:52 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_prgm.h"

void	launch_prgm(char *map_file)
{
	t_file	file;
	t_data	*data;
//	t_texture *app_texture;

	//app_texture = NULL;
	file.name = map_file;
	file.map_index = 0;
	file.fd = -1;
	data = set_parameters(&file);
	if (!data)
	{
		// error
	}
	else
	{
	print_2d_array(data->map->content);
	free_map(data->map, data->map->height);
	free_texture(&data->texture);
	free(data);
	}
}
