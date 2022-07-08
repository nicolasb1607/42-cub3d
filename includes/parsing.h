/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:57:16 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/08 16:21:23 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

//######################################################################
//#                               set_parameters.c                     #
//######################################################################

void	*set_parameters(t_data *data, t_file *file);
int		set_player(t_data *data);

//######################################################################
//#                               set_texture.c                        #
//######################################################################

int		set_texture(t_texture *texture, t_file *file);
char	*get_direction(char *line, int *i);
int		get_texture(char *line, t_texture *texture);
int		is_all_texture_set(t_texture *texture);
int		is_allowed_char(char c);

//######################################################################
//#                               set_map.c                            #
//######################################################################

void	*set_map(t_map *map, t_file *file);
void	get_map_size(int fd, t_map *map);
int		get_map_content(t_file *file, t_map *map);
void	*fill_map(t_file *file, t_map *map);
char	*collect_data_from_line(char *line, char *content);

//######################################################################
//#                               check.c                              #
//######################################################################

int		check_extension(char *file_name, char *extension);
int		check_map(t_map *map);
int		check_map_size(t_map *map);
int		check_player(t_map *map);
int		is_a_player(char c);

//######################################################################
//#                               color.c                              #
//######################################################################

int		is_rgb_format(char *str_color);
int		assign_color(char *str_color, t_color *color);
int		set_color(t_data *data);

#endif
