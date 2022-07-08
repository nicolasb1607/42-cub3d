/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:41:40 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 09:27:06 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_facing_values(t_ray *ray)
{
	if (ray->rad_angle > PI / 2 && ray->rad_angle < (3 * PI) / 2)
	{
		ray->facing_left_right = LEFT;
		ray->increment_left_right = 0;
	}
	else
	{
		ray->facing_left_right = RIGHT;
		ray->increment_left_right = 1;
	}
	if (ray->rad_angle > PI && ray->rad_angle < 2 * PI)
	{
		ray->facing_up_down = UP;
		ray->increment_top_down = 0;
	}
	else
	{
		ray->facing_up_down = DOWN;
		ray->increment_top_down = 1;
	}
}

int	adjust_coordonate(t_ray *ray, int coordonate, int hit_direction)
{
	if (hit_direction == HORIZONTAL)
	{
		if (ray->facing_up_down == UP)
			return (coordonate - 1);
		return (coordonate);
	}
	else
	{
		if (ray->facing_left_right == LEFT)
			return (coordonate - 1);
		return (coordonate);
	}
}

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	update_closest_wall(t_ray *ray, int orientation, int distance)
{
	if (orientation == VERTICAL)
	{
		ray->closest_wall.x = ray->vertical_hit.x;
		ray->closest_wall.y = ray->vertical_hit.y;
		ray->distance = distance;
		if (ray->facing_left_right == LEFT)
			ray->orientation = WEST;
		else
			ray->orientation = EAST;
	}
	else if (orientation == HORIZONTAL)
	{
		ray->closest_wall.x = ray->horizontal_hit.x;
		ray->closest_wall.y = ray->horizontal_hit.y;
		ray->distance = distance;
		if (ray->facing_up_down == DOWN)
			ray->orientation = SOUTH;
		else
			ray->orientation = NORTH;
	}
}

int	ray_is_hiting_a_wall(t_map *map, int x, int y)
{
	if (x <= 0 || x >= TILE_SIZE * map->width
		|| y <= 0 || y >= TILE_SIZE * map->height)
		return (TRUE);
	if (map->content[y / TILE_SIZE][x / TILE_SIZE] == '1')
		return (TRUE);
	return (FALSE);
}
