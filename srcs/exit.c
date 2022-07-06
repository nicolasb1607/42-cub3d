/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:31:24 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/06 10:10:03 by rpottier         ###   ########.fr       */
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
	free(data->map->floor_color);
	free(data->map->ceiling_color);
	free(data);
	exit(status);
}
