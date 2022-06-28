/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:02:37 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/28 10:27:31 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "mapping.h"

void	draw_grid(t_data *data)
{
	int	hor;
	int vert;
	t_2d a;
	t_2d b;
	
	hor = 0;
	vert = 0;
	while(hor <= data->map->width)
	{
		a.x = WIDTH_WIN / data->map->width * hor * MINIMAP_SCALE;
		a.y = 0;
		b.x = WIDTH_WIN / data->map->width * hor * MINIMAP_SCALE;
		b.y = HEIGHT_WIN * MINIMAP_SCALE;
		bresenham(a, b, data);
		hor++;
	}
	while(vert <= data->map->height)
	{
		a.x = 0;
		a.y = HEIGHT_WIN / data->map->height * vert * MINIMAP_SCALE;
		b.x = WIDTH_WIN * MINIMAP_SCALE;
		b.y = HEIGHT_WIN / data->map->height * vert * MINIMAP_SCALE;
		bresenham(a, b, data);
		vert++;
	}
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;
	t_rectangle rec;
	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			rec.x_top_left_corner = j * TILE_SIZE * MINIMAP_SCALE;
			rec.y_top_left_corner = i * TILE_SIZE * MINIMAP_SCALE;
			rec.width_size = TILE_SIZE * MINIMAP_SCALE;
			rec.height_size = TILE_SIZE * MINIMAP_SCALE;
			set_tile_color(data, i, j);
			draw_rec(&rec, data, TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data)
{

}

void	set_tile_color(t_data *data, int i, int j)
{
	if (data->map->content[i][j] == '1')
	{
		data->ceiling_color->red = 255;
		data->ceiling_color->green = 255;
		data->ceiling_color->blue = 255;
	}
	else
	{
		data->ceiling_color->red = 0;
		data->ceiling_color->green = 0;
		data->ceiling_color->blue = 0;
	}	
}
