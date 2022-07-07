/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:39:46 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/07 10:43:03 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"


int	get_pixel_color(t_ray *ray, t_texture *texture, int line_ot_pick)
{
	int colum_to_pick;
	int img_to_pick;
	int color;
	char	*dst;
	if (ray->orientation == NORTH)
	{
		colum_to_pick = (int)ray->closest_wall.x % TILE_SIZE;
		img_to_pick = NORTH;
	}
	else if (ray->orientation == SOUTH)
	{
		colum_to_pick = (int)ray->closest_wall.x % TILE_SIZE;
		img_to_pick = SOUTH;
	}
	else if (ray->orientation == WEST)
	{
		colum_to_pick = (int)ray->closest_wall.y % TILE_SIZE;
		img_to_pick = WEST;
	}
	else if (ray->orientation == EAST)
	{
		colum_to_pick = (int)ray->closest_wall.y % TILE_SIZE;
		img_to_pick = EAST;
	}
	dst = texture->tx[img_to_pick].addr + (line_ot_pick * texture->tx[img_to_pick].line_length + colum_to_pick * (texture->tx[img_to_pick].bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void draw_walls(t_data *data, t_list *all_rays)
{
	int		i;
	t_ray * ray;
	i = 0;
	while (i < NUMBER_OF_RAYS)
	{
		ray = (t_ray *)all_rays->content;
		draw_strip_wall(i, ray, data);
		all_rays = all_rays->next;
		i++;
	}

	// hauteur en pixel d un mur en fonction de la resolution

	// wall_projected = tile_size * (distance_player_projection_wall / distance_wall)
}
void draw_strip_wall(int i, t_ray *ray, t_data *data)
{
	t_2d	start;
	t_2d	end;
	t_2d	pix;
	int		color;
	double correct_distance;
	double wall_strip_height;
	double	offset;
	double line_to_pick = 0;
	double display_ratio;
	
	correct_distance = ray->distance * cos(ray->rad_angle - data->player->rotation_angle);
	wall_strip_height = (TILE_SIZE / correct_distance) * DISTANCE_PROJ_PLANE;

	if (wall_strip_height > HEIGHT_WIN)
	{
		display_ratio = HEIGHT_WIN / wall_strip_height;
		line_to_pick = (64 - (64 * display_ratio)) / 2;
		printf("HEIGHT_WIN = %d\n", HEIGHT_WIN);
		printf("wall_strip_height = %f\n", wall_strip_height);
		printf("display_ratio = %f\n", display_ratio);
		printf("line_to_pick = %f\n", line_to_pick);
	}
	start.x = i * WIDTH_RAY;
	end.x = start.x + WIDTH_RAY - 1;
	start.y = HEIGHT_WIN / 2 - wall_strip_height / 2;
	end.y = HEIGHT_WIN / 2 + wall_strip_height / 2;
	pix.x = start.x;
	offset = TILE_SIZE / wall_strip_height;
	if (wall_strip_height > HEIGHT_WIN)
	{
		offset = (64.00 * (display_ratio)) / HEIGHT_WIN;
///		printf("(64.00 * (1 - display_ratio)) = %f\n", (64.00 * (1 - display_ratio)));
	printf("offset %f\n\n", offset);
	}
//	printf("offset %f\n", offset);
	while (pix.x <= end.x)
	{
		pix.y = 0;
		while (pix.y <= HEIGHT_WIN)
		{
			if (pix.y < start.y)
				color = encode_rgb(data->texture->ceiling_color->red, data->texture->ceiling_color->green, data->texture->ceiling_color->blue);
			else if (pix.y > end.y)
				color = encode_rgb(data->texture->floor_color->red, data->texture->floor_color->green, data->texture->floor_color->blue);
			else
			{
				
//				printf("%f\n", line_to_pick);
				color = get_pixel_color(ray, data->texture, line_to_pick);
				line_to_pick += offset;
			}
			my_mlx_pixel_put(pix.x, pix.y, data->gui->img_data, color);
			pix.y++;
		}
		pix.x++;
	}
}


/*
void draw_walls(t_data *data, t_list *all_rays)
{
	t_ray	*ray;
	double	wall_strip_height;
	int		i;

	i = 0;
	while (i < NUMBER_OF_RAYS && all_rays)
	{
		ray = (t_ray *)all_rays->content;

//		printf("ray->distance = %f\n", ray->distance);
		double correct_distance = ray->distance * cos(ray->rad_angle - data->player->rotation_angle);
//		printf("correct_distance = %f\n", correct_distance);
//		wall_strip_height = (TILE_SIZE / ray->distance) * DISTANCE_PROJ_PLANE;
		wall_strip_height = (TILE_SIZE / correct_distance) * DISTANCE_PROJ_PLANE;
		
		draw_strip_wall(i, wall_strip_height, data);
		all_rays = all_rays->next;
		i++;
	}

	// hauteur en pixel d un mur en fonction de la resolution

	// wall_projected = tile_size * (distance_player_projection_wall / distance_wall)
}
*/