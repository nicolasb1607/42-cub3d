/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:00:19 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 09:19:37 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"

void	bresenham(t_2d a, t_2d b, t_data *data)
{
	t_line	line;

	create_line_data(a, b, &line);
	line.color = set_rgb_color(data->texture.minimap_color.red,
			data->texture.minimap_color.green,
			data->texture.minimap_color.blue);
	put_line(a, b, data->gui.img_data, &line);
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

void	draw_rec(t_rectangle *rect, t_data *data, int rec_size)
{
	int		i;
	t_2d	a;
	t_2d	b;

	i = 0;
	while (i < rec_size)
	{
		a.x = rect->x_top_left_corner;
		a.y = rect->y_top_left_corner + i;
		b.x = rect->x_top_left_corner + rec_size;
		b.y = rect->y_top_left_corner + i;
		bresenham(a, b, data);
		i++;
	}
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	set_rgb_color(int r_grad, int g_grad, int b_grad)
{
	return (encode_rgb(r_grad, g_grad, b_grad));
}
