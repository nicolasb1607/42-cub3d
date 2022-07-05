/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:58:10 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/05 10:24:31 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:02:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/05 10:15:40 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"


t_list	*cast_all_ray(t_player *player, t_map *map);
t_ray	*cast_ray(double angle, t_player *player, t_map *map);
void	set_facing_values(t_ray *ray);
void	get_horizontal_hit(t_ray *ray, t_player *player, t_map *map);
void	get_vertical_hit(t_ray *ray, t_player *player, t_map *map);
void	get_shortest_distance(t_ray *ray, t_player *player);
int		adjust_coordonate(t_ray *ray, int coordonate, int hit_direction);
int		is_inside_map(int x, int y, t_map *map);
double	distance(double x1, double y1, double x2, double y2);
void	update_closest_wall(t_ray *ray, int orientation, int distance);

#endif