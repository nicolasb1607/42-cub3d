/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:31:12 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/01 13:49:43 by rpottier         ###   ########.fr       */
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
	struct s_player		*player;
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

//######################################################################
//#                          GUI                                       #
//######################################################################

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

typedef struct s_player
{
	double	x_pos;
	double	y_pos;
	int		width;
	int		height;
	int		left_right_rotation;
	int		walk_direction;
	double	side_move_angle;
	double	rotation_angle;
	int		walk_speed;
	double	rotation_speed;
}	t_player;


//######################################################################
//#                          drawing                                   #
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

typedef struct s_rectangle
{
	int x_top_left_corner;
	int y_top_left_corner;
	int width_size;
	int height_size;
}	t_rectangle;

typedef struct s_ray
{
	double				rad_angle;
	struct s_2d_point	first_intersection;
	struct s_2d_point	second_intersection;
	int					x_step;
	int					y_step;
	struct s_2d_point	vertical_hit;
	struct s_2d_point	horizontal_hit;
	struct s_2d_point	closest_wall;
	double				facing_left_right;
	double				facing_top_down;
	int					increment_left_right;
	int					increment_top_down;
	double				distance;
} 	t_ray;

#endif
