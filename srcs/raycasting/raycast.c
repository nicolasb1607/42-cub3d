/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:02:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/01 16:48:25 by rpottier         ###   ########.fr       */
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
	printf("ray->rad_angle = %f\n", ray->rad_angle);
	set_facing_values(ray);
	get_horizontal_hit(ray, player, map);
	get_vertical_hit(ray, player, map);
	get_shortest_distance(ray, player);
	return (ray);
}



void	set_facing_values(t_ray *ray)
{
	double	angle;

	angle = fmod(ray->rad_angle, 2 * PI);
	if (angle > PI / 2 && angle < (3 * PI) / 2)
	{
		ray->facing_left_right = -1;
		ray->increment_left_right = 0;
	}
	else
	{
		ray->facing_left_right = 1;
		ray->increment_left_right = 1;
	}
	if (angle > PI && angle < 2 * PI)
	{
		ray->facing_top_down = -1;
		ray->increment_top_down = 0;
	}
	else
	{
		ray->facing_top_down = 1;
		ray->increment_top_down = 1;	
	}
		
}

int	check_right_case(t_ray *ray, int intersection_y)
{
	if (ray->facing_top_down < 0)
		return (intersection_y - 1);
	return (intersection_y);
}

void	get_horizontal_hit(t_ray *ray, t_player *player, t_map *map)
{
	t_2d next_intersection;
	


	printf("player->y_pos %f\n", player->y_pos);
	printf("player->x_pos %f\n", player->x_pos);
	// CALCUL FIRST INTERSECTION
	ray->first_intersection.y = (int)((player->y_pos / TILE_SIZE) + ray->increment_top_down) * TILE_SIZE ;
	ray->first_intersection.x = (int)player->x_pos + (((player->y_pos - ray->first_intersection.y) / tan(ray->rad_angle)) * ray->facing_top_down);

//	printf("(player->y_pos / TILE_SIZE) + ray->increment_top_down %f\n", (int(player->y_pos / TILE_SIZE) + ray->increment_top_down);
	printf("ray->first_intersection.y %d\n", ray->first_intersection.y);
	printf("ray->first_intersection.x %d\n", ray->first_intersection.x);
	
	if(is_hiting_a_wall(map, ray->first_intersection.x, check_right_case(ray, ray->first_intersection.y)))
	{
		ray->horizontal_hit.x = ray->first_intersection.x;
		ray->horizontal_hit.y = ray->first_intersection.y;
		printf("TEMOIN\n");
		return ;
	}
	// CALCUL SECOND INTERSECTIONL

	ray->second_intersection.y = ray->first_intersection.y + (TILE_SIZE * ray->facing_top_down);
	printf("ray->second_intersection.y %d \n", ray->second_intersection.y);

//	printf("ICI %d %d %d %f %f\n", ray->second_intersection.x, ray->first_intersection.y, ray->second_intersection.y, ray->rad_angle, ray->facing_top_down );
	ray->second_intersection.x = ray->first_intersection.x + (((ray->first_intersection.y - ray->second_intersection.y) / tan(ray->rad_angle)) * ray->facing_top_down);
	printf("ray->second_intersection.x %d \n", ray->second_intersection.x);

	printf("ICI %d\n", ray->second_intersection.y);
	if(is_hiting_a_wall(map, ray->second_intersection.x,check_right_case(ray, ray->second_intersection.y)))
	{
		ray->horizontal_hit.x = ray->second_intersection.x;
		ray->horizontal_hit.y = ray->second_intersection.y;

		printf("ray->horizontal_hit.y %d\n",ray->horizontal_hit.y);
		printf("OUT\n");
		return ;
	}
	// CALCUL STEPS
	ray->y_step = TILE_SIZE * ray->facing_top_down;
	ray->x_step = TILE_SIZE / tan(ray->rad_angle) * ray->facing_left_right;
	next_intersection.x = ray->second_intersection.x * ray->x_step;
	next_intersection.y = ray->second_intersection.y * ray->y_step;
	while (!is_hiting_a_wall(map, next_intersection.x, check_right_case(ray, next_intersection.y)))
	{
		next_intersection.x += ray->x_step;
		next_intersection.y += ray->y_step;
	}
	ray->horizontal_hit.x = next_intersection.x;
	ray->horizontal_hit.y = next_intersection.y;
	printf("ray->horizontal_hit.y %d\n", ray->horizontal_hit.y);
	printf("ray->horizontal_hit.x %d\n", ray->horizontal_hit.x);
	return ;	
}

void	get_vertical_hit(t_ray *ray, t_player *player, t_map *map)
{
	t_2d next_intersection;
	
	
	// CALCUL FIRST INTERSECTION
	ray->first_intersection.x = ((player->x_pos / TILE_SIZE) + ray->increment_left_right) * TILE_SIZE;
	ray->first_intersection.y = player->y_pos + (ray->first_intersection.x - player->x_pos) * tan(ray->rad_angle) * ray->facing_left_right;
	if(is_hiting_a_wall(map, ray->first_intersection.x, ray->first_intersection.y))
	{
		ray->vertical_hit.x = ray->first_intersection.x;
		ray->vertical_hit.y = ray->first_intersection.y;
		return ;
	}
	// CALCUL SECOND INTERSECTION
	ray->second_intersection.x +=  TILE_SIZE * ray->facing_left_right;
	ray->second_intersection.y =  ray->first_intersection.y + (TILE_SIZE * tan(ray->rad_angle)) * ray->facing_top_down;
	if(is_hiting_a_wall(map, ray->second_intersection.x, ray->second_intersection.y))
	{
		ray->vertical_hit.x = ray->second_intersection.x;
		ray->vertical_hit.y = ray->second_intersection.y;
		return ;
	}
	// CALCUL STEPS
	ray->y_step = (TILE_SIZE / tan(ray->rad_angle)) * ray->facing_top_down;
	ray->x_step = TILE_SIZE * ray->facing_left_right;
	next_intersection.x = ray->second_intersection.x * ray->x_step;
	next_intersection.y = ray->second_intersection.y * ray->y_step;
	while (!is_hiting_a_wall(map, next_intersection.x, next_intersection.y))
	{
		next_intersection.x += ray->x_step;
		next_intersection.y += ray->y_step;
	}
	ray->vertical_hit.x = next_intersection.x;
	ray->vertical_hit.y = next_intersection.y;
	return ;	
}



void	get_shortest_distance(t_ray *ray, t_player *player)
{
	float	vertical_distance;
	float	horizontal_distance;


	printf("in get_shortest_distance:\nhorizontal_hit.x:%d ray->horizontal_hit.y:%d\n", ray->horizontal_hit.x , ray->horizontal_hit.y);
	vertical_distance = sqrt(pow(abs(ray->vertical_hit.x - (int)player->x_pos), 2) + pow(abs(ray->vertical_hit.y - (int)player->y_pos), 2));
	horizontal_distance = sqrt(pow(abs(ray->horizontal_hit.x - (int)player->x_pos), 2) + pow(abs(ray->horizontal_hit.y - (int)player->y_pos), 2));
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
	printf("in get_shortest_distance:\n%f %f\n", vertical_distance , horizontal_distance);
	return ;
}