/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:09:50 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/24 15:44:20 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "cub3d.h"

void	free_texture(t_texture **texture);
void	free_map(t_map *map, int size);
t_map	*alloc_map_content(t_map *map);
void	free_gui(t_gui *gui);
void	free_color(t_color *color);

#endif