/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:18:09 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/26 16:00:44 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "cub3d.h"

void	bresenham(t_2d a, t_2d b, t_data *data);
void	create_line_data(t_2d a, t_2d b, t_line *line);
void	put_line(t_2d a, t_2d b, t_img_data *img, t_line *line, int color);
void	dx_put_line(t_2d a, t_img_data *img, t_line *line, int color);
void	dy_put_line(t_2d a, t_img_data *img, t_line *line, int color);
void	horizontal_line(t_2d a, t_2d b, t_img_data *img, int color);
void	vertical_line(t_2d a, t_2d b, t_img_data *img, int color);
int		encode_rgb(int red, int green, int blue);
int		set_rgb_color(int r_grad, int g_grad, int b_grad);
#endif
