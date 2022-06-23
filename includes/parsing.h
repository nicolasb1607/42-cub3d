/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:57:16 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/23 09:50:12 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

//######################################################################
//#                               set_parameters.c                     #
//######################################################################

t_data		*set_parameters(t_file	*file);

//######################################################################
//#                               set_texture.c                        #
//######################################################################

t_texture	*set_texture(t_file *file);
char		*get_direction(char *line, int *i);
int			get_texture(char *line, t_texture *texture);
int			is_all_texture_set(t_texture *texture);
int			is_allowed_char(char c);

//######################################################################
//#                               set_map.c                            #
//######################################################################


t_map	*set_map(t_file *file);
void	get_map_size(int fd, t_map *map);
int		get_map_content(t_file *file, t_map *map);
void	*fill_map(t_file *file, t_map *map);
char	*collect_data_from_line(char *line, char *content);


//######################################################################
//#                               check.c                            #
//######################################################################

int	check_extension(char *file_name, char *extension);

#endif
