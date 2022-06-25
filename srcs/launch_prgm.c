/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:15:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/25 15:29:26 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_prgm.h"

//	# define ft_calloc(...) NULL
void	draw_rectangle(t_data *data)
{
	t_2d a;
	t_2d b;

	a.x = 10;
	a.y = 10;
	b.x = 10;
	b.y = HEIGH-10;
	bresenham(a, b, data->gui->img_data, 200);
	
	a.x = 10;
	a.y = 10;
	b.x = WIDTH-10;
	b.y = 10;
	bresenham(a, b, data->gui->img_data, 200);

	a.x = WIDTH-10;
	a.y = 10;
	b.x = WIDTH-10;
	b.y = HEIGH-10;
	bresenham(a, b, data->gui->img_data, 200);
	
	a.x = 10;
	a.y = HEIGH-10;
	b.x = WIDTH-10;
	b.y = HEIGH-10;
	bresenham(a, b, data->gui->img_data, 200);
}

void	test_bresenham(t_data *data)
{
	draw_rectangle(data);
	mlx_put_image_to_window(data->gui->mlx, data->gui->win, data->gui->img_data->img, 0, 0);
}

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
		test_bresenham(data);
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
