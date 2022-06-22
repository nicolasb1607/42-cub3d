/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:25:04 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/22 16:26:05 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "cub3d.h"

int	check_extension(char *file_name, char *extension);

int	check_map(t_map *map);
int check_map_size(t_map *map);
int	check_player(t_map *map);
int	is_a_player(char c);

int	check_closed_map(t_map *map);
int	check_up_wall(t_map *map, int i, int j);
int	check_down_wall(t_map *map, int i, int j);
int	check_left_wall(t_map *map, int i, int j);
int	check_right_wall(t_map *map, int i, int j);

#endif