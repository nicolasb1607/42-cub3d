/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:10:45 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/07 14:21:12 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

//t_texture	*init_texture(void);

void	init_texture(t_texture	*texture);
void		init_t_file(t_file *file, char *file_name);
t_gui		*init_gui(void);

#endif