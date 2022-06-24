/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:18:09 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/23 19:19:34 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

typedef struct s_3d_point
{
	int	x;
	int	y;
	int	z;
}	t_3d;

typedef struct s_line_data
{
	int			ex;
	int			ey;
	int			dx;
	int			dy;
	int			y;
	int			const_x;
	int			const_y;
	int			x_incr;
	int			y_incr;
}	t_line;

#endif