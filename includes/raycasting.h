/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:58:10 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/02 16:02:32 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"


int		check_right_case(t_ray *ray, int coordonate, int hit_direction);
void	get_shortest_distance(t_ray *ray, t_player *player);
void	set_facing_values(t_ray *ray);
void	get_vertical_hit(t_ray *ray, t_player *player, t_map *map);
void	get_horizontal_hit(t_ray *ray, t_player *player, t_map *map);
t_ray	*cast_ray(double angle, t_player *player, t_map *map);

void	new_get_horizontal_hit(t_ray *ray, t_player *player, t_map *map);

void	new_get_vertical_hit(t_ray *ray, t_player *player, t_map *map);
#endif