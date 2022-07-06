/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:52:50 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/06 13:26:52 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_texture	*init_texture(void)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
	{
		ft_putstr_fd(ERROR_MALLOC, 2);
		return (NULL);
	}
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->floor = NULL;
	texture->ceiling = NULL;
	return (texture);
}

void	init_t_file(t_file *file, char *file_name)
{
	file->name = file_name;
	file->map_index = 0;
	file->fd = -1;
}

t_gui	*init_gui(void)
{
	t_gui	*gui;

	gui = ft_calloc(1, sizeof(t_gui));
	if (!gui)
		return (NULL);
	gui->win = NULL;
	gui->mlx = NULL;
	gui->mlx = mlx_init();
	if (!gui->mlx)
		return (free(gui), NULL);
	gui->img_data = ft_calloc(1, sizeof(t_img_data));
	if (!gui->img_data)
		return (free_gui(gui), NULL);
	gui->img_data->img = mlx_new_image(gui->mlx, WIDTH_WIN, HEIGHT_WIN);
	if (!gui->img_data->img)
		return (free_gui(gui), NULL);
	gui->img_data->addr = mlx_get_data_addr(gui->img_data->img,
			&gui->img_data->bits_per_pixel, &gui->img_data->line_length,
			&gui->img_data->endian);
	if (!gui->img_data->addr)
		return (free_gui(gui), NULL);
	gui->win = mlx_new_window(gui->mlx, WIDTH_WIN, HEIGHT_WIN, "cube3d");
	if (!gui->win)
		return (free_gui(gui), NULL);
	return (gui);
}
