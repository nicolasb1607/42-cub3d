/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:05:42 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 13:52:17 by rpottier         ###   ########.fr       */
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

void	calcul_wall_strip_heigh(t_data *data, t_strip *strip)
{
//	strip->line_to_pick = 0;
	strip->corrected_distance = strip->ray->distance * cos(strip->ray->rad_angle - data->player.rotation_angle);
	strip->wall_strip_height = (TILE_SIZE / strip->corrected_distance) * DISTANCE_PROJ_PLANE;
}

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

