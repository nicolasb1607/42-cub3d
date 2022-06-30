/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:02:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/30 10:21:45 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"


void	get_horizontal_hit(t_ray *ray, t_player *player, t_map *map)
{
	// CALCUL FIRST INTERSECTION
	ray->first_intersection.y = (player.y_pos / TILE_SIZE) * TILE_SIZE;
	ray->first_intersection.x = player.x_pos + ((player.y_pos - ray->first_intersection.y) / tan(ray->rad_angle));
	if(is_hiting_a_wall(map, ray->first_intersection.x, ray->first_intersection.y))
	{
		ray->horizontal_hit.x = ray->first_intersection.x;
		ray->horizontal_hit.y = ray->first_intersection.y;
		return ;
	}
	// CALCUL SECOND INTERSECTION
	ray->second_intersection.y = (ray->first_intersection.y / TILE_SIZE) * TILE_SIZE;
	ray->second_intersection.x = ray->first_intersection.x + ((ray->first_intersection.y - ray->second_intersection.y) / tan(ray->rad_angle));
	if(is_hiting_a_wall(map, ray->second_intersection.x, ray->second_intersection.y))
	{
		ray->horizontal_hit.x = ray->second_intersection.x;
		ray->horizontal_hit.y = ray->second_intersection.y;
		return ;
	}
	// CALCUL STEPS
	ray->y_step = TILE_SIZE;
	ray->x_step = TILE_SIZE / tan(ray->rad_angle);
	while (is)
	{
		/* code */
	}
	
	
}

t_ray	cast_ray(float angle, t_player player, t_map *map)
{
	t_ray *ray;

	ray = ft_calloc(1, sizeof(t_ray));
	if(!ray)
		return(ft_putstr_fd(ERROR_MALLOC, 2), NULL);
	ray->rad_angle = angle;
	get_horizontal_hit(ray, player);
	

	returne(ray)
}

