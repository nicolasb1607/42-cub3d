/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:02:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/02 18:29:16 by rpottier         ###   ########.fr       */
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
	printf("1 ray->rad_angle = %f\n", ray->rad_angle);
//	ray->rad_angle = fmod(ray->rad_angle, 2 * PI);
	if (ray->rad_angle < 0)
	 	ray->rad_angle += (2 * PI);
	printf("2 ray->rad_angle = %f\n", ray->rad_angle);
	set_facing_values(ray);
	new_get_horizontal_hit(ray, player, map);
	new_get_vertical_hit(ray, player, map);
	get_shortest_distance(ray, player);
	return (ray);
}

# define LEFT -1
# define RIGHT 1
# define UP -1
# define DOWN 1

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

# define HORIZONTAL 0
# define VERTICAL 1

int	check_right_case(t_ray *ray, int coordonate, int hit_direction)
{
	if (hit_direction == HORIZONTAL)
	{
		if (ray->facing_up_down == UP)
			return (coordonate - 1);
		return (coordonate+1);
	}
	else
	{
		if (ray->facing_left_right == LEFT)
			return (coordonate - 1);
		return (coordonate+1);
	}
}

int is_inside_map(int x, int y, t_map *map)
{
	if (x >= 0 && x < map->width * TILE_SIZE && y >= 0 && y < map->height * TILE_SIZE)
		return (TRUE);
	else
		return (FALSE);
}


void	new_get_horizontal_hit(t_ray *ray, t_player *player, t_map *map)
{

	// CALCUL FIRST INTERSECTION
	
	printf("new ray->rad_angle = %f\n", ray->rad_angle);
	printf("ray->increment_top_down %d\n", ray->increment_top_down);
	ray->intersection.y = (floor((player->y_pos / TILE_SIZE)) + ray->increment_top_down) * TILE_SIZE ;


	printf("(ray->intersection.y - player->y_pos) = %f ray->rad_angle %f tan(ray->rad_angle) =%f\n", (ray->intersection.y - player->y_pos), ray->rad_angle, tan(ray->rad_angle));
	printf("%f\n", ((ray->intersection.y - player->y_pos)) / tan(ray->rad_angle));
	printf("%f %f %f\n", player->x_pos, ray->intersection.y, player->y_pos);
	
	printf("ray->intersection.x = %f \n", ray->intersection.x);
	ray->intersection.x = player->x_pos + (((ray->intersection.y - player->y_pos) / tan(ray->rad_angle)) * ray->facing_up_down);

//	printf("ray->intersection.x = %f ray->intersection.y = %f\n", ray->intersection.x, ray->intersection.y);
	ray->y_step = TILE_SIZE * ray->facing_up_down;
	ray->x_step = (TILE_SIZE / tan(ray->rad_angle));

	if (ray->x_step > 0 && ray->facing_left_right == LEFT)
		ray->x_step *= -1;
	if (ray->x_step < 0 && ray->facing_left_right == RIGHT)
		ray->x_step *= -1;

	ray->exist_horizontal_hit = FALSE;
	printf("x_step = %d\n", ray->x_step);
	printf("ray->intersection.x = %f ray->intersection.y = %f\n", ray->intersection.x, ray->intersection.y);
	while (ray->intersection.y >= 0 && ray->intersection.y < TILE_SIZE * map->height && ray->intersection.x >= 0 && ray->intersection.x < TILE_SIZE * map->width)
	{
		if (is_hiting_a_wall(map, ray->intersection.x, check_right_case(ray,ray->intersection.y, HORIZONTAL)))
		{
			ray->horizontal_hit.x = ray->intersection.x;
			ray->horizontal_hit.y = ray->intersection.y;
			ray->exist_horizontal_hit = TRUE;
			printf("FOUND\n");
			break ;
		}
		else
		{
			ray->intersection.x += ray->x_step;
			ray->intersection.y += ray->y_step;
		}
	printf("ray->intersection.x = %f ray->intersection.y = %f\n", ray->intersection.x, ray->intersection.y);
	}
}

void	get_horizontal_hit(t_ray *ray, t_player *player, t_map *map)
{
	t_2d next_intersection;
	


	// printf("player->y_pos %f\n", player->y_pos);
	// printf("player->x_pos %f\n", player->x_pos);
	// CALCUL FIRST INTERSECTION
	ray->first_intersection.y = (int)((player->y_pos / TILE_SIZE) + ray->increment_top_down) * TILE_SIZE ;
	ray->first_intersection.x = (int)player->x_pos + (((ray->first_intersection.y - player->y_pos) / tan(ray->rad_angle)) * ray->facing_up_down);

//	printf("(player->y_pos / TILE_SIZE) + ray->increment_top_down %f\n", (int(player->y_pos / TILE_SIZE) + ray->increment_top_down);
	// printf("ray->first_intersection.y %d\n", ray->first_intersection.y);
	// printf("ray->first_intersection.x %d\n", ray->first_intersection.x);
	
	if(is_inside_map(ray->first_intersection.x, ray->first_intersection.y, map) && is_hiting_a_wall(map,  ray->first_intersection.x, check_right_case(ray, ray->first_intersection.y, HORIZONTAL)))
	{
		ray->horizontal_hit.x = ray->first_intersection.x;
		ray->horizontal_hit.y = ray->first_intersection.y;
//		printf("TEMOIN\n");
		return ;
	}
	// CALCUL SECOND INTERSECTIONL

	ray->second_intersection.y = ray->first_intersection.y + (TILE_SIZE * ray->facing_up_down);
//	printf("ray->second_intersection.y %d \n", ray->second_intersection.y);

//	printf("ICI %d %d %d %f %f\n", ray->second_intersection.x, ray->first_intersection.y, ray->second_intersection.y, ray->rad_angle, ray->facing_up_down );
	ray->second_intersection.x = ray->first_intersection.x + (((ray->first_intersection.y - ray->second_intersection.y) / tan(ray->rad_angle)) * ray->facing_up_down);
	// printf("ray->second_intersection.x %d \n", ray->second_intersection.x);

	// printf("ICI %d\n", ray->second_intersection.y);
	if(is_inside_map(ray->second_intersection.x, ray->second_intersection.y, map) && is_hiting_a_wall(map, ray->second_intersection.x,check_right_case(ray, ray->second_intersection.y, HORIZONTAL)))
	{
		ray->horizontal_hit.x = ray->second_intersection.x;
		ray->horizontal_hit.y = ray->second_intersection.y;

		// printf("ray->horizontal_hit.x %d\n",ray->horizontal_hit.x);
		// printf("ray->horizontal_hit.y %d\n",ray->horizontal_hit.y);
		// printf("OUT\n");
		return ;
	}
	// CALCUL STEPS
	ray->y_step = TILE_SIZE * ray->facing_up_down;
	ray->x_step = TILE_SIZE / tan(ray->rad_angle) * ray->facing_left_right;
	next_intersection.x = ray->second_intersection.x * ray->x_step;
	next_intersection.y = ray->second_intersection.y * ray->y_step;
	while (is_inside_map(next_intersection.x, next_intersection.y, map))
	{
		if (is_hiting_a_wall(map, next_intersection.x, check_right_case(ray, next_intersection.y, HORIZONTAL)))
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
	// printf("ray->horizontal_hit.y %d\n", ray->horizontal_hit.y);
	// printf("ray->horizontal_hit.x %d\n", ray->horizontal_hit.x);
	return ;	
}

void	new_get_vertical_hit(t_ray *ray, t_player *player, t_map *map)
{
	// CALCUL FIRST INTERSECTION
//	printf("ray->increment_left_right %d\n", ray->increment_left_right);
	ray->intersection.x = (floor((player->x_pos / TILE_SIZE)) + ray->increment_left_right) * TILE_SIZE;
//	printf("ray->intersection.x ===== %f\n", ray->intersection.x);
	ray->intersection.y = player->y_pos + ((ray->intersection.x - player->x_pos) * tan(ray->rad_angle) * ray->facing_left_right);

	ray->x_step = TILE_SIZE * ray->facing_left_right;
//	printf("x_step %d\n", ray->x_step);
	ray->y_step = TILE_SIZE * tan(ray->rad_angle);
	if (ray->y_step > 0 && ray->facing_up_down == UP)
		ray->y_step *= -1;
	if (ray->y_step < 0 && ray->facing_up_down == DOWN	)
		ray->y_step *= -1;
//	printf("y_step %d\n", ray->y_step);
//	printf("ray->intersection.x = %f ray->intersection.y = %f\n", ray->intersection.x, ray->intersection.y);

	ray->exist_vertical_hit = FALSE;
	while (ray->intersection.y >= 0 && ray->intersection.y < TILE_SIZE * map->height && ray->intersection.x >= 0 && ray->intersection.x < TILE_SIZE * map->width)
	{
		if (is_hiting_a_wall(map, check_right_case(ray,ray->intersection.x, VERTICAL), ray->intersection.y))
		{
			ray->vertical_hit.x = ray->intersection.x;
			ray->vertical_hit.y = ray->intersection.y;
			ray->exist_vertical_hit = TRUE;
//			printf("FOUND\n");
			break ;
		}
		else
		{
			ray->intersection.x += ray->x_step;
			ray->intersection.y += ray->y_step;
		}
//		printf("ray->intersection.x = %f ray->intersection.y = %f\n", ray->intersection.x, ray->intersection.y);
	}
}

void	get_vertical_hit(t_ray *ray, t_player *player, t_map *map)
{
	t_2d next_intersection;
	
	printf("player->y_pos %f\n", player->y_pos);
	printf("player->x_pos %f\n", player->x_pos);
	// CALCUL FIRST INTERSECTION
	ray->first_intersection.x = (int)((player->x_pos / TILE_SIZE) + ray->increment_left_right) * TILE_SIZE;
	ray->first_intersection.y = (int)player->y_pos + (((player->x_pos - ray->first_intersection.x) * tan(ray->rad_angle)) * ray->facing_left_right);
	printf("ray->first_intersection.y %f\n", ray->first_intersection.y);
	printf("ray->first_intersection.x %f\n", ray->first_intersection.x);
	if(is_inside_map(ray->first_intersection.x, ray->first_intersection.y, map) && is_hiting_a_wall(map, check_right_case(ray, ray->first_intersection.x, VERTICAL),ray->first_intersection.y))
	{
		ray->vertical_hit.x = ray->first_intersection.x;
		ray->vertical_hit.y = ray->first_intersection.y;
		return ;
	}
	// CALCUL SECOND INTERSECTION
	ray->second_intersection.x +=  TILE_SIZE * ray->facing_left_right;
	ray->second_intersection.y =  ray->first_intersection.y + (TILE_SIZE * tan(ray->rad_angle)) * ray->facing_up_down;
	printf("ray->second_intersection.y %f \n", ray->second_intersection.y);

	printf("ICI %f\n", ray->second_intersection.y);
	if(is_inside_map(ray->second_intersection.x, ray->second_intersection.y, map) && is_hiting_a_wall(map, check_right_case(ray, ray->second_intersection.x, VERTICAL), ray->second_intersection.y))
	{
		ray->vertical_hit.x = ray->second_intersection.x;
		ray->vertical_hit.y = ray->second_intersection.y;
		printf("ray->vertical_hit.x %f\n",ray->vertical_hit.x);
		printf("ray->vertical_hit.y %f\n",ray->vertical_hit.y);
		printf("OUT\n");
		return ;
	}
	// CALCUL STEPS
	ray->y_step = (TILE_SIZE / tan(ray->rad_angle)) * ray->facing_up_down;
	ray->x_step = TILE_SIZE * ray->facing_left_right;
	next_intersection.x = ray->second_intersection.x * ray->x_step;
	next_intersection.y = ray->second_intersection.y * ray->y_step;
	while (is_inside_map(next_intersection.x, next_intersection.y, map) && !is_hiting_a_wall(map, check_right_case(ray, next_intersection.x, VERTICAL), next_intersection.y))
	{
		next_intersection.x += ray->x_step;
		next_intersection.y += ray->y_step;
	}
	ray->vertical_hit.x = next_intersection.x;
	ray->vertical_hit.y = next_intersection.y;
	printf("ray->vertical_hit.y %f\n", ray->vertical_hit.y);
	printf("ray->vertical_hit.x %f\n", ray->vertical_hit.x);
	return ;	
}

double	distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void	get_shortest_distance(t_ray *ray, t_player *player)
{
	double	vertical_distance;
	double	horizontal_distance;


	printf("in get_shortest_distance:\nhorizontal_hit.x:%f ray->horizontal_hit.y:%f\n", ray->horizontal_hit.x , ray->horizontal_hit.y);
	printf("vertical_hit.x:%f ray->vertical_hit.y:%f\n", ray->vertical_hit.x , ray->vertical_hit.y);
	// vertical_distance = sqrt(pow(ft_abs_double(ray->vertical_hit.x - player->x_pos), 2) + pow(ft_abs_double(ray->vertical_hit.y - player->y_pos), 2));
	// horizontal_distance = sqrt(pow(ft_abs_double(ray->horizontal_hit.x - player->x_pos), 2) + pow(ft_abs_double(ray->horizontal_hit.y - player->y_pos), 2));
	vertical_distance = distanceBetweenPoints(player->x_pos, player->y_pos, ray->vertical_hit.x, ray->vertical_hit.y);
	horizontal_distance = distanceBetweenPoints(player->x_pos, player->y_pos, ray->horizontal_hit.x, ray->horizontal_hit.y);
	printf("%d %d\n", ray->exist_horizontal_hit, ray->exist_vertical_hit);
	
	
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
	printf("in get_shortest_distance:\n%f %f\n", vertical_distance , horizontal_distance);
	return ;
}