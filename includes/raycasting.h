/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:58:10 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/08 15:33:09 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

//######################################################################
//#                          raycast.c                                 #
//######################################################################

t_list	*cast_all_ray(t_player *player, t_map *map);
t_ray	*cast_ray(double angle, t_player *player, t_map *map);
void	get_horizontal_hit(t_ray *ray, t_player *player, t_map *map);
void	get_vertical_hit(t_ray *ray, t_player *player, t_map *map);
void	get_shortest_distance(t_ray *ray, t_player *player);

//######################################################################
//#                          raycast_utils.c                           #
//######################################################################

void	set_facing_values(t_ray *ray);
int		adjust_coordonate(t_ray *ray, int coordonate, int hit_direction);
void	update_closest_wall(t_ray *ray, int orientation, int distance);
int		ray_is_hiting_a_wall(t_map *map, int x, int y);
double	distance(double x1, double y1, double x2, double y2);

//######################################################################
//#                          raycast_orientation.c                     #
//######################################################################

double	find_x_step_orientation(double x_step, int facing_left_right);
double	find_y_step_orientation(double y_step, int facing_up_down);
int		is_inside_map(t_map *map, int intersection_x, int intersection_y);

#endif