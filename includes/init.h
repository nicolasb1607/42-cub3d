/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:10:45 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 15:29:29 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

void	init_texture(t_texture	*texture);
void	init_t_file(t_file *file, char *file_name);
void	*init_gui(t_gui *gui);

#endif