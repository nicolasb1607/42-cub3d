/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:57:16 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/20 14:44:43 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"


int			check_extension(char *file_name, char *extension);
t_texture	*set_parameters(int fd);
int			set_texture(char *line, t_texture *texture);
char		*get_direction(char *line, int *i);

int	is_allowed_char(char c);
int	is_all_texture_set(t_texture *texture);

#endif