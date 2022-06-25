/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:36:44 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/25 15:00:45 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_pixel.h"

void	my_mlx_pixel_put(int x, int y, t_img_data *img, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH - 1 || y < 0 || y > HEIGH - 1)
		return ;
	dst = img->addr + (y * img->line_length + x
			* (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
