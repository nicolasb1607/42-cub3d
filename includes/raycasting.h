/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:58:10 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/04 16:32:28 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

t_ray	*cast_ray(double angle, t_player *player, t_map *map);
void	set_facing_values(t_ray *ray);
int		adjust_coordonate(t_ray *ray, int coordonate, int hit_direction);
int		is_inside_map(int x, int y, t_map *map);
void	get_horizontal_hit(t_ray *ray, t_player *player, t_map *map);
void	get_vertical_hit(t_ray *ray, t_player *player, t_map *map);
double	distance(double x1, double y1, double x2, double y2);
void	get_shortest_distance(t_ray *ray, t_player *player);
t_list	*cast_all_ray(t_player *player, t_map *map);

#endif