/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:09:14 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/08 16:14:57 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_and_destroy_texture(t_texture *texture, void *mlx)
{
	free_texture(texture);
	destroy_texture_img(texture, mlx);
}

void	destroy_texture_img(t_texture *texture, void *mlx)
{
	if (texture->tx[NORTH].img)
		mlx_destroy_image(mlx, texture->tx[NORTH].img);
	if (texture->tx[SOUTH].img)
		mlx_destroy_image(mlx, texture->tx[SOUTH].img);
	if (texture->tx[EAST].img)
		mlx_destroy_image(mlx, texture->tx[EAST].img);
	if (texture->tx[WEST].img)
		mlx_destroy_image(mlx, texture->tx[WEST].img);
}

void	free_texture(t_texture *texture)
{
	if (texture->north)
		free(texture->north);
	if (texture->south)
		free(texture->south);
	if (texture->west)
		free(texture->west);
	if (texture->east)
		free(texture->east);
	if (texture->floor)
		free(texture->floor);
	if (texture->ceiling)
		free(texture->ceiling);
}

void	free_map(t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map->content[i]);
		i++;
	}
	free(map->content);
}

void	free_gui(t_gui *gui)
{
	if (gui->img_data)
	{
		if (gui->img_data->img)
			mlx_destroy_image(gui->mlx, gui->img_data->img);
		free(gui->img_data);
	}
	if (gui->win)
		mlx_destroy_window(gui->mlx, gui->win);
	if (gui->mlx)
	{
		mlx_destroy_display(gui->mlx);
		free(gui->mlx);
	}
}
