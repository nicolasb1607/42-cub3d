/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:02:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 09:49:07 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_list	*cast_all_ray(t_player *player, t_map *map)
{
	t_list	*all_rays;
	t_ray	*ray;
	double	ray_angle;
	double	angle_incr;
	int		i;

	angle_incr = FOV / NUMBER_OF_RAYS;
	ray_angle = player->rotation_angle - (FOV / 2);
	all_rays = NULL;
	i = 0;
	while (i < NUMBER_OF_RAYS)
	{
		refactor_angle(&ray_angle);
		ray = cast_ray(ray_angle, player, map);
		ft_lstadd_back(&all_rays, ft_lstnew(ray));
		ray_angle += angle_incr;
		i++;
	}
	return (all_rays);
}

t_ray	*cast_ray(double angle, t_player *player, t_map *map)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	if (!ray)
		return (ft_putstr_fd(ERROR_MALLOC, 2), NULL);
	ray->rad_angle = angle;
	set_facing_values(ray);
	get_horizontal_hit(ray, player, map);
	get_vertical_hit(ray, player, map);
	get_shortest_distance(ray, player);
	return (ray);
}

void	get_horizontal_hit(t_ray *ray, t_player *player, t_map *map)
{
	ray->intersection.y = (floor(player->y / TILE_SIZE)
			+ ray->increment_top_down) * TILE_SIZE;
	ray->intersection.x = player->x
		+ (((ray->intersection.y - player->y) / tan(ray->rad_angle)));
	ray->y_step = TILE_SIZE * ray->facing_up_down;
	ray->x_step = (TILE_SIZE / tan(ray->rad_angle));
	ray->x_step = find_x_step_orientation(ray->x_step, ray->facing_left_right);
	ray->exist_horizontal_hit = FALSE;
	while (is_inside_map(map, ray->intersection.x, ray->intersection.y))
	{
		if (ray_is_hiting_a_wall(map, ray->intersection.x,
				adjust_coordonate(ray, ray->intersection.y, HORIZONTAL)))
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
	ray->intersection.x = (floor(player->x / TILE_SIZE)
			+ ray->increment_left_right) * TILE_SIZE;
	ray->intersection.y = player->y
		+ ((ray->intersection.x - player->x) * tan(ray->rad_angle));
	ray->x_step = TILE_SIZE * ray->facing_left_right;
	ray->y_step = TILE_SIZE * tan(ray->rad_angle);
	ray->y_step = find_y_step_orientation(ray->y_step, ray->facing_up_down);
	ray->exist_vertical_hit = FALSE;
	while (is_inside_map(map, ray->intersection.x, ray->intersection.y))
	{
		if (ray_is_hiting_a_wall(map,
				adjust_coordonate(ray, ray->intersection.x, VERTICAL),
				ray->intersection.y))
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

void	get_shortest_distance(t_ray *ray, t_player *player)
{
	double	vertical_distance;
	double	horizontal_distance;

	vertical_distance = distance(player->x, player->y,
			ray->vertical_hit.x, ray->vertical_hit.y);
	horizontal_distance = distance(player->x, player->y,
			ray->horizontal_hit.x, ray->horizontal_hit.y);
	if (ray->exist_horizontal_hit && ray->exist_vertical_hit)
	{
		if (vertical_distance <= horizontal_distance)
			update_closest_wall(ray, VERTICAL, vertical_distance);
		else
			update_closest_wall(ray, HORIZONTAL, horizontal_distance);
	}
	else if (ray->exist_horizontal_hit)
		update_closest_wall(ray, HORIZONTAL, horizontal_distance);
	else
		update_closest_wall(ray, VERTICAL, vertical_distance);
	return ;
}
