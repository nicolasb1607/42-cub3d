/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:11:04 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 16:19:55 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

void	update_player(t_data *data);
int		glide_x(t_player *player, t_data *data, int new_x);
void	glide_y(t_player *player, t_data *data, int new_y);
int		ray_is_hiting_a_wall(t_map *map, int x, int y);
int		player_is_hiting_a_wall(t_map *map, int x, int y);
void	refactor_angle(double *angle);

#endif
