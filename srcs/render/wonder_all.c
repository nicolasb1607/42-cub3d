/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wonder_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:39:46 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/05 14:55:59 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

/*
my_mlx_pixel_put(a.x, a.y, img, color);
*/

void draw_strip_wall(int i, int wall_strip_height, t_data *data)
{
	t_2d start;
	t_2d end;
	t_2d pix;
	int color;

	start.x = i * WIDTH_RAY;
	end.x = start.x + WIDTH_RAY - 1;
	start.y = HEIGHT_WIN / 2 - wall_strip_height / 2;
	end.y = HEIGHT_WIN / 2 + wall_strip_height / 2;

	pix.x = start.x;

	while (pix.x < end.x)
	{
		pix.y = 0;
		while (pix.y < HEIGHT_WIN)
		{
			if (pix.y < start.y)
				color = encode_rgb(0, 0, 255);
			else if (pix.y > end.y)
				color = encode_rgb(0, 255, 0);
			else
				color = encode_rgb(255,255,255);
			my_mlx_pixel_put(pix.x, pix.y, data->gui->img_data, color);
			pix.y++;
		}
		pix.x++;
	}
}

void draw_walls(t_data *data, t_list *all_rays)
{
	t_ray *ray;
	double wall_strip_height;
	int i;

	i = 0;
	while (i < NUMBER_OF_RAYS && all_rays)
	{
		ray = (t_ray *)all_rays->content;

		double correct_distance = ray->distance * cos(ray->rad_angle - data->player->rotation_angle);
//		wall_strip_height = (TILE_SIZE / ray->distance) * DISTANCE_PROJ_PLANE;
		wall_strip_height = (TILE_SIZE / correct_distance) * DISTANCE_PROJ_PLANE;
		
		draw_strip_wall(i, wall_strip_height, data);
		all_rays = all_rays->next;
		i++;
	}

	// hauteur en pixel d un mur en fonction de la resolution

	// wall_projected = tile_size * (distance_player_projection_wall / distance_wall)
}