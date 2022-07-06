/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:09:14 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/06 10:08:41 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_texture(t_texture **texture)
{
	if ((*texture)->north)
		free((*texture)->north);
	if ((*texture)->south)
		free((*texture)->south);
	if ((*texture)->west)
		free((*texture)->west);
	if ((*texture)->east)
		free((*texture)->east);
	if ((*texture)->floor)
		free((*texture)->floor);
	if ((*texture)->ceiling)
		free((*texture)->ceiling);
	free((*texture));
	*texture = NULL;
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
	free(map);
}

t_map	*alloc_map_content(t_map *map)
{
	int	i;

	map->content = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->content)
	{
		ft_putstr_fd(ERROR_MALLOC, 2);
		return (NULL);
	}
	i = 0;
	while (i < map->height)
	{
		map->content[i] = ft_calloc(map->width + 1, sizeof(char));
		if (!map->content[i])
		{
			free_map(map, i);
			ft_putstr_fd(ERROR_MALLOC, 2);
			return (NULL);
		}
		ft_memset_char_bis(map->content[i], '1', map->width);
		i++;
	}
	return (map);
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
	free(gui);
}

void free_color(t_data *data)
{
	free(data->map->ceiling_color);
	free(data->map->floor_color);
}