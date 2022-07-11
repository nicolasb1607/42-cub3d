/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:05:42 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/11 10:56:54 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	get_pixel_color(t_ray *ray, t_texture *texture, int line_ot_pick)
{
	int		column_to_pick;
	int		img_to_pick;
	int		color;
	char	*dst;

	get_img_and_col_to_pick(ray, &column_to_pick, &img_to_pick);
	dst = texture->tx[img_to_pick].addr
		+ (line_ot_pick * texture->tx[img_to_pick].line_length
			+ column_to_pick * (texture->tx[img_to_pick].bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	get_img_and_col_to_pick(t_ray *ray, int *col, int *img)
{
	if (ray->orientation == NORTH)
	{
		*col = (int)ray->closest_wall.x % TILE_SIZE;
		*img = NORTH;
	}
	else if (ray->orientation == SOUTH)
	{
		*col = (int)ray->closest_wall.x % TILE_SIZE;
		*img = SOUTH;
	}
	else if (ray->orientation == WEST)
	{
		*col = (int)ray->closest_wall.y % TILE_SIZE;
		*img = WEST;
	}
	else if (ray->orientation == EAST)
	{
		*col = (int)ray->closest_wall.y % TILE_SIZE;
		*img = EAST;
	}
}

void	calcul_wall_strip_heigh(t_data *data, t_strip *strip)
{
	strip->corrected_distance = strip->ray->distance
		* cos(strip->ray->rad_angle - data->player.rotation_angle);
	strip->wall_strip_height = (TILE_SIZE / strip->corrected_distance)
		* DISTANCE_PROJ_PLANE;
}

void	get_line_to_pick(t_strip *strip)
{
	if (strip->wall_strip_height > HEIGHT_WIN)
	{
		strip->display_ratio = HEIGHT_WIN / strip->wall_strip_height;
		strip->line_to_pick = (TEXTURE_SIZE
				- (TEXTURE_SIZE * strip->display_ratio)) / 2;
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
