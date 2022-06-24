/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:31:24 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/24 16:07:27 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	ft_exit(t_data *data)
{
	int	status;
	
	status = 0;
	free_gui(data->gui);
	free_map(data->map, data->map->height);
	free_texture(&data->texture);
	free_color(data->floor_color);
	free_color(data->ceiling_color);
	free(data);
	exit(status);
}
