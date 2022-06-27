/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:02:37 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/27 14:36:30 by rpottier         ###   ########.fr       */
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
		a.x = WIDTH_WIN / data->map->width * hor * RATIO_MINIMAP;
		a.y = 0;
		b.x = WIDTH_WIN / data->map->width * hor * RATIO_MINIMAP;
		b.y = HEIGHT_WIN * RATIO_MINIMAP;
		bresenham(a, b, data);
		hor++;
	}
	while(vert <= data->map->height)
	{
		a.x = 0;
		a.y = HEIGHT_WIN / data->map->height * vert * RATIO_MINIMAP;
		b.x = WIDTH_WIN * RATIO_MINIMAP;
		b.y = HEIGHT_WIN / data->map->height * vert * RATIO_MINIMAP;
		bresenham(a, b, data);
		vert++;
	}
}

// typedef struct s_red
// {
// 	int x_top_left_corner;
// 	int y_top_left_corner;
// 	int width_size;
// 	int height_size;
// }	t_rectangle;


// void	draw_rec(t_rectangle *rect, t_data *data)
// {
// 	int	i;
// 	int	j;
// 	t_2d a;
// 	t_2d b;

// 	i = 0;
// 	while (i < TILE_SIZE)
// 	{
// 		a.x = rect->x_top_left_corner;
// 		a.y = rect->y_top_left_corner + i;
// 		b.x = rect->x_top_left_corner + TILE_SIZE;
// 		b.y = rect->y_top_left_corner + i;
// 		bresenham(a, b, data);
// 		i++;
// 	}
// }

void	draw_minimap(t_data *data)
{

	draw_grid(data);
// 	int	i;
// 	int	j;
// 	t_rectangle rec;
// 	i = 0;
// 	while (i < data->map->height)
// 	{
// 		j = 0;
// 		while (j < data->map->width)
// 		{
// 			rec.x_top_left_corner = j * TILE_SIZE;
// 			rec.y_top_left_corner = i * TILE_SIZE;
// 			rec.width_size = TILE_SIZE;
// 			rec.height_size = TILE_SIZE;
// //			printf ("%d\n", data->map->content[i][j]);
// 			if (data->map->content[i][j] == '1')
// 			{
// 				data->ceiling_color->red = 255;
// 				data->ceiling_color->green = 255;
// 				data->ceiling_color->blue = 255;
// 			}
// 			else
// 			{
// 				data->ceiling_color->red = 0;
// 				data->ceiling_color->green = 0;
// 				data->ceiling_color->blue = 0;
// 			}
// 			draw_rec(&rec, data);
// 			j++;
// 		}
// 		i++;
// 	}
}
