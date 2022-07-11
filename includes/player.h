/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:11:04 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/11 10:59:12 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

void	update_player(t_data *data);
void	glide(t_player *player, t_data *data, int new_x, int new_y);
int		ray_is_hiting_a_wall(t_map *map, int x, int y);
int		player_is_hiting_a_wall(t_map *map, int x, int y);
void	refactor_angle(double *angle);
void	apply_new_coordonate(t_data *data, int new_player_x, int new_player_y);

#endif
