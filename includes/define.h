/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:29:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/02 16:31:41 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define TRUE 1
# define FALSE 0
# define PI 3.1415926535

# define HEIGHT_WIN /*1080*//*480  */ 960 
# define WIDTH_WIN /*1920*/ /* 640*/1280  

# define MINIMAP_SCALE 1
# define TILE_SIZE 128

# define WIDTH_RAY 1
# define NUMBER_OF_RAYS (WIDTH_WIN / WIDTH_RAY)

# define WALK_SPEED 2.0
# define ROTATION_SPEED 4 * (PI / 180)
# define FOV 60 * (PI / 180)

#endif