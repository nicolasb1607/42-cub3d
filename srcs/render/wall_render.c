/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:39:46 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 12:17:21 by rpottier         ###   ########.fr       */
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


/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/



void	get_line_to_pick(t_strip *strip)
{
	if (strip->wall_strip_height > HEIGHT_WIN)
	{
		strip->display_ratio = HEIGHT_WIN / strip->wall_strip_height;
		strip->line_to_pick = (64 - (64 * strip->display_ratio)) / 2;
	}
	else
		strip->line_to_pick = 0;
}

void	set_wall_display_limits(t_strip *strip, int ray_num)
{
	strip->start.x = ray_num * WIDTH_RAY;
	strip->end.x = strip->start.x + WIDTH_RAY - 1;
	strip->start.y = HEIGHT_WIN / 2 - strip->wall_strip_height / 2;
	strip->end.y = HEIGHT_WIN / 2 + strip->wall_strip_height / 2;
	strip->pix.x = strip->start.x;
}

void	calcul_wall_strip_heigh(t_data *data, t_strip *strip)
{
//	strip->line_to_pick = 0;
	strip->corrected_distance = strip->ray->distance * cos(strip->ray->rad_angle - data->player.rotation_angle);
	strip->wall_strip_height = (TILE_SIZE / strip->corrected_distance) * DISTANCE_PROJ_PLANE;
}
void	calcul_offset(t_strip *strip)
{
	strip->offset = 64.00 / strip->wall_strip_height;
	if (strip->wall_strip_height > HEIGHT_WIN)
	{
		strip->offset = (64.00 * (strip->display_ratio)) / HEIGHT_WIN;
	}
}

void choose_pixel_color(t_data *data, t_strip *strip)
{
	if (strip->pix.y < strip->start.y)
		strip->color = encode_rgb(data->texture.ceiling_color.red, data->texture.ceiling_color.green, data->texture.ceiling_color.blue);
	else if (strip->pix.y > strip->end.y)
		strip->color = encode_rgb(data->texture.floor_color.red, data->texture.floor_color.green, data->texture.floor_color.blue);
	else
	{
		strip->color = get_pixel_color(strip->ray, &data->texture, strip->line_to_pick);
		strip->line_to_pick += strip->offset;
	}
}

void	paint_strip(t_data *data, t_strip *strip)
{
	while (strip->pix.x <= strip->end.x)
	{
		strip->pix.y = 0;
		get_line_to_pick(strip);
		while (strip->pix.y <= HEIGHT_WIN)
		{
			choose_pixel_color(data, strip);
			my_mlx_pixel_put(strip->pix.x, strip->pix.y, data->gui.img_data, strip->color);
			strip->pix.y++;
		}
		strip->pix.x++;
	}
}

void draw_strip_wall(int ray_num, t_ray *ray, t_data *data)
{
	t_strip strip;
	
	strip.ray = ray;
	calcul_wall_strip_heigh(data, &strip);
	get_line_to_pick(&strip);
	set_wall_display_limits(&strip, ray_num);
	calcul_offset(&strip);
	paint_strip(data, &strip);
}
