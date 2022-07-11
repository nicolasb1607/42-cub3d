/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:32:58 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/11 10:54:23 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	render(t_data *data)
{
	t_list	*all_rays;

	all_rays = NULL;
	update_player(data);
	all_rays = cast_all_ray(&data->player, &data->map);
	draw_walls(data, all_rays);
	ft_lstclear(&all_rays, free);
	mlx_put_image_to_window(data->gui.mlx, data->gui.win,
		data->gui.img_data->img, 0, 0);
}
