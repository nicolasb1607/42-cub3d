/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:39:46 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/11 10:18:33 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	draw_walls(t_data *data, t_list *all_rays)
{
	int		i;
	t_ray	*ray;

	i = 0;
	while (i < NUMBER_OF_RAYS)
	{
		ray = (t_ray *)all_rays->content;
		draw_strip_wall(i, ray, data);
		all_rays = all_rays->next;
		i++;
	}
}

void	calcul_offset(t_strip *strip)
{
	strip->offset = TEXTURE_SIZE / strip->wall_strip_height;
	if (strip->wall_strip_height > HEIGHT_WIN)
	{
		strip->offset = (TEXTURE_SIZE * (strip->display_ratio)) / HEIGHT_WIN;
	}
}

void	choose_pixel_color(t_data *data, t_strip *strip)
{
	if (strip->pix.y < strip->start.y)
		strip->color = encode_rgb(data->texture.ceiling_color.red,
				data->texture.ceiling_color.green,
				data->texture.ceiling_color.blue);
	else if (strip->pix.y >= strip->end.y)
		strip->color = encode_rgb(data->texture.floor_color.red,
				data->texture.floor_color.green,
				data->texture.floor_color.blue);
	else
	{
		strip->color = get_pixel_color(strip->ray,
				&data->texture,
				strip->line_to_pick);
		strip->line_to_pick += strip->offset;
	}
}

void	paint_strip(t_data *data, t_strip *strip)
{
	while (strip->pix.x <= strip->end.x)
	{
		strip->pix.y = 0;
		get_line_to_pick(strip);
		while (strip->pix.y <= HEIGHT_WIN)
		{
			choose_pixel_color(data, strip);
			my_mlx_pixel_put(strip->pix.x, strip->pix.y,
				data->gui.img_data, strip->color);
			strip->pix.y++;
		}
		strip->pix.x++;
	}
}

void	draw_strip_wall(int ray_num, t_ray *ray, t_data *data)
{
	t_strip	strip;

	strip.ray = ray;
	calcul_wall_strip_heigh(data, &strip);
	get_line_to_pick(&strip);
	set_wall_display_limits(&strip, ray_num);
	calcul_offset(&strip);
	paint_strip(data, &strip);
}
