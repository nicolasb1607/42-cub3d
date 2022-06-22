/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:15:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/22 13:06:01 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_prgm.h"

int	launch_prgm(char *file_name)
{
	t_file	file;
	t_data	*data;

	init_t_file(&file, file_name);
	data = set_parameters(&file);
	if (!data)
		return (1);
	else
	{
		print_2d_array(data->map->content);
		free_map(data->map, data->map->height);
		free_texture(&data->texture);
		free(data);
		return (0);
	}
}
