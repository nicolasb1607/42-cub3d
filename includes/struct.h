/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:31:12 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/26 16:01:27 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_file
{
	char	*name;
	int		fd;
	int		map_index;
}	t_file;

typedef struct s_data
{
	struct s_texture	*texture;
	struct s_map		*map;
	struct s_gui		*gui;
	struct s_color		*floor_color;
	struct s_color		*ceiling_color;
}	t_data;

typedef struct s_texture
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*floor;
	char			*ceiling;
}	t_texture;

typedef struct s_map
{
	char			**content;
	int				width;
	int				height;
}	t_map;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_gui
{
	void				*mlx;
	void				*win;
	struct s_img_data	*img_data;
}	t_gui;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;


//######################################################################
//#                          bresenham                                 #
//######################################################################


typedef struct s_2d_point
{
	int	x;
	int	y;
}	t_2d;

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
