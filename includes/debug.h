/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:30:14 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 15:27:07 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "cub3d.h"

void	print_param(t_texture *app_texture);
void	print_2d_array(char **array);
void	print_rgb_param(char *F_OR_C, t_color *color);
double	ft_abs_double(double nb);

#endif