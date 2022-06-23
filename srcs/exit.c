/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:31:24 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/23 16:11:23 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	ft_exit(t_data *data)
{
	free_gui(data->gui);
	free_map(data->map, data->map->height);
	free_texture(&data->texture);
	free(data);
	
	return (0);
}