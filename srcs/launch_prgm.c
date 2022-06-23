/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:15:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/23 19:03:06 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_prgm.h"

//	# define ft_calloc(...) NULL

int	launch_prgm(char *file_name)
{
	t_file	file;
	t_data	*data;
	
	
	init_t_file(&file, file_name);
	data = set_parameters(&file);
	if (!data || !check_map(data->map))
	{
		if (data)
		{
			free_map(data->map, data->map->height);
			free_texture(&data->texture);
			free(data);
		}
		return (1);
	}
	else
	{
//		print_2d_array(data->map->content);
		data->gui = init_gui();
		if (!data->gui)
		{
			ft_putstr_fd(ERROR_GUI_INIT, 2);
		//	return (1);
		}
		mlx_hook(data->gui->win, 17, 0, ft_exit, data);
		mlx_key_hook(data->gui->win, key_hook, data);
		mlx_loop(data->gui->mlx);
		// free_gui(data->gui);
		// free_map(data->map, data->map->height);
		// free_texture(&data->texture);
		// free(data);
		return (0);
	}
}
