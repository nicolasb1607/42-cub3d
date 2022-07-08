/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:33:10 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 15:15:42 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "cub3d.h"

//######################################################################
//#                          minimap.c                                 #
//######################################################################

void	draw_minimap(t_data *data);
void	draw_raycast(t_data *data, t_list *all_rays);
void	set_tile_color(t_data *data, int i, int j);

//######################################################################
//#                          wall_render.c                             #
//######################################################################

void	draw_walls(t_data *data, t_list *all_rays);
void	draw_strip_wall(int ray_num, t_ray *ray, t_data *data);
void	calcul_offset(t_strip *strip);
void	paint_strip(t_data *data, t_strip *strip);

//######################################################################
//#                          wall_render_utils.c                       #
//######################################################################

void	calcul_wall_strip_heigh(t_data *data, t_strip *strip);
void	get_line_to_pick(t_strip *strip);
void	set_wall_display_limits(t_strip *strip, int ray_num);
int		get_pixel_color(t_ray *ray, t_texture *texture, int line_ot_pick);
void	get_img_and_col_to_pick(t_ray *ray, int *col, int *img);

#endif
