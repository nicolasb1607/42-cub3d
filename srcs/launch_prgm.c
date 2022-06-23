/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:15:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/23 11:47:24 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_prgm.h"

void	free_gui(t_gui *gui)
{
	free(gui->mlx);
	free(gui->win);
	if (gui->img_data)
	{
		free(gui->img_data->img);
		free(gui->img_data->addr);
		free(gui->img_data);
	}
	free(gui);
}

t_gui	*init_gui(void)
{
	t_gui	*gui;

	gui = ft_calloc(1, sizeof(t_gui));
	if (!gui)
		return (NULL);
	gui->win = NULL;
	gui->mlx = NULL;
	gui->img_data = NULL;
	# define ft_calloc(...) NULL
	gui->img_data = ft_calloc(sizeof(t_img));
	if (!gui->img_data)
		return (free(gui), NULL);
	gui->mlx = mlx_init();
	if (!gui->mlx)
		return (free(gui), NULL);
	gui->win = mlx_new_window(gui->mlx, WIDTH, HEIGH, "cube3d");
	if (!gui->win)
		return (free(gui), NULL);
	gui->img_data->img = mlx_new_image(gui->mlx, WIDTH, HEIGH);
	if (!gui->img_data->img)
		return (free(gui), NULL);
	gui->img_data->addr = mlx_get_data_addr(gui->img_data->img,
			&gui->img_data->bits_per_pixel, &gui->img_data->line_length,
			&gui->img_data->endian);
	if (!gui->img_data->addr)
		return (free(gui), NULL);
	return (gui);
}

int	launch_prgm(char *file_name)
{
	t_file	file;
	t_data	*data;
	t_gui	*gui;
	
	init_t_file(&file, file_name);
	gui = init_gui();
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
