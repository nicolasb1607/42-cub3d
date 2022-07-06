/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:29:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/06 09:45:43 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define TRUE 1
# define FALSE 0

# define HORIZONTAL 0
# define VERTICAL 1

# define LEFT -1
# define RIGHT 1
# define UP -1
# define DOWN 1

# define PI 3.1415926535

# define HEIGHT_WIN /*1080*//*480  */ 960 
# define WIDTH_WIN /*1920*/ /* 640*/1280  

# define MINIMAP_SCALE 1
# define TILE_SIZE 64

# define WIDTH_RAY 1
# define NUMBER_OF_RAYS (WIDTH_WIN / WIDTH_RAY)

# define WALK_SPEED (TILE_SIZE / 4)
# define ROTATION_SPEED 4 * (PI / 180)
# define FOV 60 * (PI / 180)
# define DISTANCE_PROJ_PLANE ((WIDTH_WIN / 2) / tan(FOV / 2))
# define PLAYER_RADIUS ((TILE_SIZE / 3) / 2)

#endif