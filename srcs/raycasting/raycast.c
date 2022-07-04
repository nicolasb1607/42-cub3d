/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:02:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/03 19:04:51 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_ray	*cast_ray(double angle, t_player *player, t_map *map)
{
	t_ray *ray;

	ray = ft_calloc(1, sizeof(t_ray));
	if(!ray)
		return (ft_putstr_fd(ERROR_MALLOC, 2), NULL);
	ray->rad_angle = angle;
	if (ray->rad_angle < 0)
	 	ray->rad_angle += (2 * PI);
	set_facing_values(ray);
	get_horizontal_hit(ray, player, map);
	get_vertical_hit(ray, player, map);
	get_shortest_distance(ray, player);
	return (ray);
}

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
		ray->facing_up_down = 1;
		ray->increment_top_down = 1;	
	}
		
}

int	adjust_coordonate(t_ray *ray, int coordonate, int hit_direction)
{
	if (hit_direction == HORIZONTAL)
	{
		if (ray->facing_up_down == UP)
			return (coordonate - 1);
		return (coordonate + 1);
	}
	else
	{
		if (ray->facing_left_right == LEFT)
			return (coordonate - 1);
		return (coordonate + 1);
	}
}

int is_inside_map(int x, int y, t_map *map)
{
	if (x >= 0 && x < map->width * TILE_SIZE && y >= 0 && y < map->height * TILE_SIZE)
		return (TRUE);
	else
		return (FALSE);
}


void	get_horizontal_hit(t_ray *ray, t_player *player, t_map *map)
{

	// CALCUL FIRST INTERSECTION

	ray->intersection.y = (floor(player->y_pos / TILE_SIZE) + ray->increment_top_down) * TILE_SIZE ;
	ray->intersection.x = player->x_pos + (((ray->intersection.y - player->y_pos) / tan(ray->rad_angle)));

	ray->y_step = TILE_SIZE * ray->facing_up_down;
	ray->x_step = (TILE_SIZE / tan(ray->rad_angle));

	if (ray->x_step > 0 && ray->facing_left_right == LEFT)
		ray->x_step *= -1;
	if (ray->x_step < 0 && ray->facing_left_right == RIGHT)
		ray->x_step *= -1;

	ray->exist_horizontal_hit = FALSE;
	while (ray->intersection.y >= 0 && ray->intersection.y < TILE_SIZE * map->height && ray->intersection.x >= 0 && ray->intersection.x < TILE_SIZE * map->width)
	{
		if (is_hiting_a_wall(map, ray->intersection.x, adjust_coordonate(ray,ray->intersection.y, HORIZONTAL)))
		{
			ray->horizontal_hit.x = ray->intersection.x;
			ray->horizontal_hit.y = ray->intersection.y;
			ray->exist_horizontal_hit = TRUE;
			break ;
		}
		else
		{
			ray->intersection.x += ray->x_step;
			ray->intersection.y += ray->y_step;
		}
	}
}

void	get_vertical_hit(t_ray *ray, t_player *player, t_map *map)
{
	// CALCUL FIRST INTERSECTION
	ray->intersection.x = (floor((player->x_pos / TILE_SIZE)) + ray->increment_left_right) * TILE_SIZE;
	ray->intersection.y = player->y_pos + ((ray->intersection.x - player->x_pos) * tan(ray->rad_angle)/* * ray->facing_left_right*/);

	ray->x_step = TILE_SIZE * ray->facing_left_right;
	ray->y_step = TILE_SIZE * tan(ray->rad_angle);
	if (ray->y_step > 0 && ray->facing_up_down == UP)
		ray->y_step *= -1;
	if (ray->y_step < 0 && ray->facing_up_down == DOWN	)
		ray->y_step *= -1;
	ray->exist_vertical_hit = FALSE;
	while (ray->intersection.y >= 0 && ray->intersection.y < TILE_SIZE * map->height && ray->intersection.x >= 0 && ray->intersection.x < TILE_SIZE * map->width)
	{
		if (is_hiting_a_wall(map, adjust_coordonate(ray,ray->intersection.x, VERTICAL), ray->intersection.y))
		{
			ray->vertical_hit.x = ray->intersection.x;
			ray->vertical_hit.y = ray->intersection.y;
			ray->exist_vertical_hit = TRUE;
			break ;
		}
		else
		{
			ray->intersection.x += ray->x_step;
			ray->intersection.y += ray->y_step;
		}
	}
}

double	distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void	get_shortest_distance(t_ray *ray, t_player *player)
{
	double	vertical_distance;
	double	horizontal_distance;

	vertical_distance = distance(player->x_pos, player->y_pos, ray->vertical_hit.x, ray->vertical_hit.y);
	horizontal_distance = distance(player->x_pos, player->y_pos, ray->horizontal_hit.x, ray->horizontal_hit.y);
	if (ray->exist_horizontal_hit && ray->exist_vertical_hit)
	{
		if (vertical_distance < horizontal_distance)
		{
			ray->closest_wall.x = ray->vertical_hit.x;
			ray->closest_wall.y = ray->vertical_hit.y;
			ray->distance = vertical_distance;
		}
		else
		{
			ray->closest_wall.x = ray->horizontal_hit.x;
			ray->closest_wall.y = ray->horizontal_hit.y;
			ray->distance = horizontal_distance;
		}
	}
	else if (ray->exist_horizontal_hit)
	{
		ray->closest_wall.x = ray->horizontal_hit.x;
		ray->closest_wall.y = ray->horizontal_hit.y;
		ray->distance = horizontal_distance;
	}
	else
	{
		ray->closest_wall.x = ray->vertical_hit.x;
		ray->closest_wall.y = ray->vertical_hit.y;
		ray->distance = vertical_distance;
	}
	return ;
}


//######################################################################
//#                               old version                          #
//######################################################################

/*

void	get_horizontal_hit(t_ray *ray, t_player *player, t_map *map)
{
	t_2d next_intersection;
	
	ray->first_intersection.y = (int)((player->y_pos / TILE_SIZE) + ray->increment_top_down) * TILE_SIZE ;
	ray->first_intersection.x = (int)player->x_pos + (((ray->first_intersection.y - player->y_pos) / tan(ray->rad_angle)) * ray->facing_up_down);

	if(is_inside_map(ray->first_intersection.x, ray->first_intersection.y, map) && is_hiting_a_wall(map,  ray->first_intersection.x, adjust_coordonate(ray, ray->first_intersection.y, HORIZONTAL)))
	{
		ray->horizontal_hit.x = ray->first_intersection.x;
		ray->horizontal_hit.y = ray->first_intersection.y;
		return ;
	}
	// CALCUL SECOND INTERSECTIONL

	ray->second_intersection.y = ray->first_intersection.y + (TILE_SIZE * ray->facing_up_down);
	ray->second_intersection.x = ray->first_intersection.x + (((ray->first_intersection.y - ray->second_intersection.y) / tan(ray->rad_angle)) * ray->facing_up_down);
	if(is_inside_map(ray->second_intersection.x, ray->second_intersection.y, map) && is_hiting_a_wall(map, ray->second_intersection.x,adjust_coordonate(ray, ray->second_intersection.y, HORIZONTAL)))
	{
		ray->horizontal_hit.x = ray->second_intersection.x;
		ray->horizontal_hit.y = ray->second_intersection.y;
		return ;
	}
	// CALCUL STEPS
	ray->y_step = TILE_SIZE * ray->facing_up_down;
	ray->x_step = TILE_SIZE / tan(ray->rad_angle) * ray->facing_left_right;
	next_intersection.x = ray->second_intersection.x * ray->x_step;
	next_intersection.y = ray->second_intersection.y * ray->y_step;
	while (is_inside_map(next_intersection.x, next_intersection.y, map))
	{
		if (is_hiting_a_wall(map, next_intersection.x, adjust_coordonate(ray, next_intersection.y, HORIZONTAL)))
		{
			ray->horizontal_hit.x = next_intersection.x;
			ray->horizontal_hit.y = next_intersection.y;
		}
		else
		{
			next_intersection.x += ray->x_step;
			next_intersection.y += ray->y_step;
		}
	}
	return ;	
}

void	get_vertical_hit(t_ray *ray, t_player *player, t_map *map)
{
	t_2d next_intersection;

	// CALCUL FIRST INTERSECTION
	ray->first_intersection.x = (int)((player->x_pos / TILE_SIZE) + ray->increment_left_right) * TILE_SIZE;
	ray->first_intersection.y = (int)player->y_pos + (((player->x_pos - ray->first_intersection.x) * tan(ray->rad_angle)) * ray->facing_left_right);
	if(is_inside_map(ray->first_intersection.x, ray->first_intersection.y, map) && is_hiting_a_wall(map, adjust_coordonate(ray, ray->first_intersection.x, VERTICAL),ray->first_intersection.y))
	{
		ray->vertical_hit.x = ray->first_intersection.x;
		ray->vertical_hit.y = ray->first_intersection.y;
		return ;
	}
	// CALCUL SECOND INTERSECTION
	ray->second_intersection.x +=  TILE_SIZE * ray->facing_left_right;
	ray->second_intersection.y =  ray->first_intersection.y + (TILE_SIZE * tan(ray->rad_angle)) * ray->facing_up_down;
	if(is_inside_map(ray->second_intersection.x, ray->second_intersection.y, map) && is_hiting_a_wall(map, adjust_coordonate(ray, ray->second_intersection.x, VERTICAL), ray->second_intersection.y))
	{
		ray->vertical_hit.x = ray->second_intersection.x;
		ray->vertical_hit.y = ray->second_intersection.y;
		return ;
	}
	// CALCUL STEPS
	ray->y_step = (TILE_SIZE / tan(ray->rad_angle)) * ray->facing_up_down;
	ray->x_step = TILE_SIZE * ray->facing_left_right;
	next_intersection.x = ray->second_intersection.x * ray->x_step;
	next_intersection.y = ray->second_intersection.y * ray->y_step;
	while (is_inside_map(next_intersection.x, next_intersection.y, map) && !is_hiting_a_wall(map, adjust_coordonate(ray, next_intersection.x, VERTICAL), next_intersection.y))
	{
		next_intersection.x += ray->x_step;
		next_intersection.y += ray->y_step;
	}
	ray->vertical_hit.x = next_intersection.x;
	ray->vertical_hit.y = next_intersection.y;
	return ;	
}
*/
