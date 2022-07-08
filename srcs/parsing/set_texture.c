/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:23:09 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 16:22:18 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	set_texture(t_texture *texture, t_file *file)
{
	char	*line;

	line = NULL;
	init_texture(texture);
	line = get_next_line(file->fd);
	file->map_index++;
	while (is_all_texture_set(texture) == 0 && line != NULL)
	{
		if (get_texture(line, texture) == -1)
			break ;
		free (line);
		line = get_next_line(file->fd);
		file->map_index++;
	}
	free (line);
	if (!is_all_texture_set(texture))
		return (ft_putstr_fd(ERROR_MISSING_TEXTURE, 2), close(file->fd), 0);
	texture->file_name[NORTH] = texture->north;
	texture->file_name[SOUTH] = texture->south;
	texture->file_name[EAST] = texture->east;
	texture->file_name[WEST] = texture->west;
	return (1);
}

char	*get_direction(char *line, int *i)
{
	char	*direction;

	direction = NULL;
	while (line[*i] && ft_is_sp_or_tab(line[*i]))
		(*i)++;
	while (line[*i] && !ft_is_sp_or_tab(line[*i]))
	{
		direction = ft_charjoin(direction, line[*i]);
		(*i)++;
	}
	while (line[*i] && ft_is_sp_or_tab(line[*i]))
		(*i)++;
	return (direction);
}

int	get_texture(char *line, t_texture *texture)
{
	int		i;
	char	*direction;

	i = 0;
	direction = get_direction(line, &i);
	if (*direction == '\n')
		return (free(direction), 0);
	if (!texture->north && ft_strcmp("NO", direction) == 0)
		texture->north = ft_strdup_no_nl(&line[i]);
	else if (!texture->south && ft_strcmp("SO", direction) == 0)
		texture->south = ft_strdup_no_nl(&line[i]);
	else if (!texture->east && ft_strcmp("EA", direction) == 0)
		texture->east = ft_strdup_no_nl(&line[i]);
	else if (!texture->west && ft_strcmp("WE", direction) == 0)
		texture->west = ft_strdup_no_nl(&line[i]);
	else if (!texture->floor && ft_strcmp("F", direction) == 0)
		texture->floor = ft_strdup_no_nl(&line[i]);
	else if (!texture->ceiling && ft_strcmp("C", direction) == 0)
		texture->ceiling = ft_strdup_no_nl(&line[i]);
	else
		return (free(direction), -1);
	return (free(direction), 0);
}

int	is_all_texture_set(t_texture *texture)
{
	if (texture && (texture->north == NULL
			|| texture->south == NULL
			|| texture->west == NULL
			|| texture->east == NULL
			|| texture->floor == NULL
			|| texture->ceiling == NULL))
		return (0);
	else
		return (1);
}

int	is_allowed_char(char c)
{	
	if (c == 'N'
		|| c == 'S'
		|| c == 'E'
		|| c == 'W'
		|| c == '0'
		|| c == '1'
		|| c == ' ')
		return (1);
	else
		return (0);
}
