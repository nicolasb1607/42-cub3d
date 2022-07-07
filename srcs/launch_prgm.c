/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:15:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/07 21:30:06 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_prgm.h"

//	# define ft_calloc(...) NULL

int	launch_prgm(char *file_name)
{
	t_data	data;
	t_file	file;

	ft_memset(&data, 0, sizeof(t_data));
	init_t_file(&file, file_name);
	if(!set_parameters(&data, &file))
		return (FAILURE);
	else
	{
		render(&data);
		mlx_setting_loop_hooks(&data);
		return (SUCCESS);
	}
	return (SUCCESS);
}


int	load_texture(t_data	*data)
{
	int	i;

	data->texture.tx[NORTH].img = mlx_xpm_file_to_image(data->gui.mlx, data->texture.north, &data->texture.tx[NORTH].width, &data->texture.tx[NORTH].height);
	data->texture.tx[SOUTH].img = mlx_xpm_file_to_image(data->gui.mlx, data->texture.south, &data->texture.tx[SOUTH].width, &data->texture.tx[SOUTH].height);
	data->texture.tx[EAST].img = mlx_xpm_file_to_image(data->gui.mlx, data->texture.east, &data->texture.tx[EAST].width, &data->texture.tx[EAST].height);
	data->texture.tx[WEST].img = mlx_xpm_file_to_image(data->gui.mlx, data->texture.west, &data->texture.tx[WEST].width, &data->texture.tx[WEST].height);

	printf("%d %d\n", data->texture.tx[NORTH].width, data->texture.tx[NORTH].height);
	i = 0;
	while (i < 4)
	{
		if (data->texture.tx[i].img == NULL)
		{
			return (FAILURE);
		}
		i++;
	}
	data->texture.tx[NORTH].addr = mlx_get_data_addr(data->texture.tx[NORTH].img, &data->texture.tx[NORTH].bits_per_pixel, &data->texture.tx[NORTH].line_length, &data->texture.tx[NORTH].endian);
	data->texture.tx[SOUTH].addr = mlx_get_data_addr(data->texture.tx[SOUTH].img, &data->texture.tx[SOUTH].bits_per_pixel, &data->texture.tx[SOUTH].line_length, &data->texture.tx[SOUTH].endian);
	data->texture.tx[EAST].addr =  mlx_get_data_addr(data->texture.tx[EAST].img, &data->texture.tx[EAST].bits_per_pixel, &data->texture.tx[EAST].line_length, &data->texture.tx[EAST].endian);
	data->texture.tx[WEST].addr =  mlx_get_data_addr(data->texture.tx[WEST].img, &data->texture.tx[WEST].bits_per_pixel, &data->texture.tx[WEST].line_length, &data->texture.tx[WEST].endian);

	i = 0;
	while (i < 4)
	{
		if (!data->texture.tx[i].img || !data->texture.tx[i].addr)
		{
			i = 0;
			while (i < 4)
			{
				free(data->texture.tx[i].img);
				free(data->texture.tx[i].addr);
				i++;
			}
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}


void refresh_img(t_data *data)
{
	//reset_img(data);
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
			my_mlx_pixel_put(x, y, data->gui.img_data, encode_rgb(0, 0, 0));
			x++;
		}
		y++;
	}
}