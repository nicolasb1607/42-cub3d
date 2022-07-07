/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:32:58 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/07 21:16:44 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	render(t_data *data)
{
	t_list *all_rays = NULL;

	update_player(data);
	all_rays = cast_all_ray(&data->player, &data->map);
	draw_walls(data, all_rays);
//	draw_minimap(data);
//	draw_raycast(data, all_rays);
	ft_lstclear(&all_rays, free);
	mlx_put_image_to_window(data->gui.mlx, data->gui.win,
		data->gui.img_data->img, 0, 0);
	
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;

	t_rectangle rec;
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
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
/*
void	draw_player(t_data *data)
{
	
}
*/
void draw_raycast(t_data *data, t_list *all_rays)
{
	t_ray	*ray;
	t_2d	a;
	t_2d	b;

	while (all_rays)
	{
		ray = (t_ray*)all_rays->content;
		a.x = data->player.x_pos;
		a.y = data->player.y_pos;
		b.x = ray->closest_wall.x;
		b.y = ray->closest_wall.y;
		
		if (ray->facing_left_right == RIGHT)
			b.x = b.x - 1;
		if (ray->facing_up_down == DOWN)
			b.y = b.y - 1;

		// printf("draw_raycating\n");

		// printf("%f %f\n", ray->closest_wall.x, ray->closest_wall.y);
		// printf("%d %d\n", b.x, b.y);
		// set_color player
		data->texture.minimap_color.red = 255;
		data->texture.minimap_color.green = 0;
		data->texture.minimap_color.blue = 0;

		bresenham(a, b, data);
		all_rays = all_rays->next;
	}
}

void	set_tile_color(t_data *data, int i, int j)
{
	if (data->map.content[i][j] == '1')
	{
		data->texture.minimap_color.red = 255;
		data->texture.minimap_color.green = 255;
		data->texture.minimap_color.blue = 255;
	}
	else
	{
		data->texture.minimap_color.red = 0;
		data->texture.minimap_color.green = 0;
		data->texture.minimap_color.blue = 0;
	}	
}
