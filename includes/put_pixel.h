/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:37:21 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 15:32:20 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_PIXEL_H
# define PUT_PIXEL_H

# include "cub3d.h"

void	my_mlx_pixel_put(int x, int y, t_img_data *img, int color);

#endif