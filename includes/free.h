/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:09:50 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/07 19:57:36 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "cub3d.h"

//void	free_texture(t_texture **texture);

void	free_and_destroy_texture(t_texture *texture, void *mlx);
void	destroy_texture_img(t_texture *texture, void *mlx);
void	free_texture(t_texture *texture);

//void	free_texture(t_texture *texture);

void	free_map(t_map *map, int size);
t_map	*alloc_map_content(t_map *map);
void	free_gui(t_gui *gui);
#endif