/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_orientation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:41:38 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 09:45:36 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double	find_x_step_orientation(double x_step, int facing_left_right)
{
	if (x_step > 0 && facing_left_right == LEFT)
		x_step *= -1;
	if (x_step < 0 && facing_left_right == RIGHT)
		x_step *= -1;
	return (x_step);
}

double	find_y_step_orientation(double y_step, int facing_up_down)
{
	if (y_step > 0 && facing_up_down == UP)
		y_step *= -1;
	if (y_step < 0 && facing_up_down == DOWN)
		y_step *= -1;
	return (y_step);
}

int	is_inside_map(t_map *map, int intersection_x, int intersection_y)
{
	if (intersection_y >= 0
		&& intersection_y < TILE_SIZE * map->height
		&& intersection_x >= 0
		&& intersection_x < TILE_SIZE * map->width)
		return (TRUE);
	return (FALSE);
}
