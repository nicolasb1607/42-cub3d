/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:31:24 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 14:58:33 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	ft_exit_status(t_data *data, int status)
{
	if (status == SET_PARAMS_FAILURE)
	{
		free_texture(&data->texture);
	}
	else if (status == INIT_GUI_FAILURE)
	{
		free_texture(&data->texture);
		free_map(&data->map, data->map.height);
		ft_putstr_fd(ERROR_GUI_INIT, 2);
	}
	else if (status == LOAD_TEXTURE_FAILURE)
	{
		free_map(&data->map, data->map.height);
		free_and_destroy_texture(&data->texture, data->gui.mlx);
		free_gui(&data->gui);
		ft_putstr_fd(ERROR_LOAD_TEXTURE, 2);
	}
	else if (status == FREE_ALL)
	{
		free_map(&data->map, data->map.height);
		free_and_destroy_texture(&data->texture, data->gui.mlx);
		free_gui(&data->gui);
	}
	exit(status);
}

int	ft_exit_red_cross(t_data *data)
{
	int	status;

	status = FREE_ALL;
	ft_exit_status(data, status);
	return (status);
}
