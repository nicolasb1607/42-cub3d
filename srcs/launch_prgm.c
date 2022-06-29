/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:15:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/29 14:10:42 by nburat-d         ###   ########.fr       */
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
			free(data->floor_color);
			free(data->ceiling_color);
			free_map(data->map, data->map->height);
			free_texture(&data->texture);
			free(data);
		}
		return (-1);
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
		render(data);
		mlx_setting_loop_hooks(data);
		return (0);
	}
}


void	render(t_data *data)
{
//	printf("render\n");
	draw_minimap(data);
	update_player(data);
	draw_player(data);
	mlx_put_image_to_window(data->gui->mlx, data->gui->win,
		data->gui->img_data->img, 0, 0);
}

void refresh_img(t_data *data)
{
	reset_img(data);
	render(data);
}

void	reset_img(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT_WIN)
	{
		x = 0;
		while (x < WIDTH_WIN)
		{
			my_mlx_pixel_put(x, y, data->gui->img_data, encode_rgb(0, 0, 0));
			x++;
		}
		y++;
	}
}