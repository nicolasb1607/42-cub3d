/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:05:38 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/27 14:34:45 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPPING_H
# define MAPPING_H

# include "cub3d.h"

# define RATIO_MINIMAP 0.7
# define TILE_SIZE 32

typedef struct s_rectangle
{
	int x_top_left_corner;
	int y_top_left_corner;
	int width_size;
	int height_size;
}	t_rectangle;

void	draw_rec(t_rectangle *rect, t_data *data);
void	draw_minimap(t_data *data);

#endif