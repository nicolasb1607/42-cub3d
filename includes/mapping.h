/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:05:38 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/04 09:19:01 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPPING_H
# define MAPPING_H

# include "cub3d.h"

void	update_player(t_data *data);
void	draw_minimap(t_data *data);
void	draw_player(t_data *data);
void	draw_rec(t_rectangle *rect, t_data *data, int rec_size);
void	set_tile_color(t_data *data, int i, int j);
int		is_hiting_a_wall(t_map *map, int x, int y);
void	draw_raycasting(t_data *data, t_ray *ray);
void	update_player(t_data *data);

#endif