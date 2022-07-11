/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:15:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/11 10:56:11 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_prgm.h"

int	launch_prgm(char *file_name)
{
	t_data	data;
	t_file	file;

	ft_memset(&data, 0, sizeof(t_data));
	init_t_file(&file, file_name);
	if (!set_parameters(&data, &file))
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

	i = 0;
	while (i < 4)
	{
		data->texture.tx[i].img = mlx_xpm_file_to_image(data->gui.mlx,
				data->texture.file_name[i],
				&data->texture.tx[i].width, &data->texture.tx[i].height);
		data->texture.tx[i].addr = mlx_get_data_addr(data->texture.tx[i].img,
				&data->texture.tx[i].bits_per_pixel,
				&data->texture.tx[i].line_length,
				&data->texture.tx[i].endian);
		if (data->texture.tx[i].width != TEXTURE_SIZE
			|| data->texture.tx[i].height != TEXTURE_SIZE)
		{
			ft_putstr_fd(ERROR_TEXTURE_SIZE, 2);
			return (FAILURE);
		}
		if (data->texture.tx[i].addr == NULL || data->texture.tx[i].img == NULL)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

void	refresh_img(t_data *data)
{
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
