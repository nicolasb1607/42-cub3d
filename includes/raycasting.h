/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:58:10 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/01 13:49:43 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

void	get_shortest_distance(t_ray *ray, t_player *player);
void	set_facing_values(t_ray *ray);
void	get_vertical_hit(t_ray *ray, t_player *player, t_map *map);
void	get_horizontal_hit(t_ray *ray, t_player *player, t_map *map);
t_ray	*cast_ray(double angle, t_player *player, t_map *map);

#endif