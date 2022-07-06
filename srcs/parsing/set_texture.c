/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:23:09 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/06 12:04:09 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_texture	*set_texture(t_file *file)
{
	char		*line;
	t_texture	*app_texture;

	line = NULL;
	app_texture = init_texture();
	if (!app_texture)
		return (NULL);
	line = get_next_line(file->fd);
	file->map_index++;
	while (is_all_texture_set(app_texture) == 0 && line != NULL)
	{
		if (get_texture(line, app_texture) == -1)
			break ;
		free (line);
		line = get_next_line(file->fd);
		file->map_index++;
	}
	free (line);
	if (is_all_texture_set(app_texture) == 0)
	{
		ft_putstr_fd(ERROR_MISSING_TEXTURE, 2);
		close(file->fd);
		return (free_texture(&app_texture), NULL);
	}
	// app_texture->tx[NORTH].img = ;
	// app_texture->tx[SOUTH] = ;
	// app_texture->tx[EAST] = ;
	// app_texture->tx[WEST] = ;
	return (app_texture);
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
