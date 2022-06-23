/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:09:50 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/23 09:50:06 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "cub3d.h"

void	free_texture(t_texture **texture);
void	free_map(t_map *map, int size);
t_map	*alloc_map_content(t_map *map);

#endif