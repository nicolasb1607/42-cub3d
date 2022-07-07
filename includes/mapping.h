/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:05:38 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/07 18:44:57 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPPING_H
# define MAPPING_H

# include "cub3d.h"

void	update_player(t_data *data);
int		ray_is_hiting_a_wall(t_map *map, int x, int y);
int		player_is_hiting_a_wall(t_map *map, int x, int y);
//void	set_tile_color(t_data *data, int i, int j);

#endif
