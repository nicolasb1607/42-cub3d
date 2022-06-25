/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:32:44 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/25 15:01:45 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"

void	bresenham(t_2d a, t_2d b, t_img_data *img, int color)
{
	t_line	line;

	create_line_data(a, b, &line);
	put_line(a, b, img, &line, color);
}

void	create_line_data(t_2d a, t_2d b, t_line *line)
{
	line->ex = abs(b.x - a.x);
	line->ey = abs(b.y - a.y);
	line->dx = 2 * line->ex;
	line->dy = 2 * line->ey;
	line->const_x = line->ex;
	line->const_y = line->ey;
	line->x_incr = 1;
	line->y_incr = 1;
	if (a.x > b.x)
		line->x_incr = -1;
	if (a.y > b.y)
		line->y_incr = -1;
}
