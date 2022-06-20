/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:03:25 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/20 14:40:06 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"parsing.h"

int	is_allowed_char(char c)
{	
	if (c == 'N'
			|| c == 'S'
			|| c == 'E'
			|| c == 'W'
			|| c == 'F'
			|| c == 'C')
		return (1);
	else
		return (0);
}

int	is_all_texture_set(t_texture *texture)
{
	if (texture->north == NULL ||
			texture->south == NULL ||
			texture->west == NULL ||
			texture->east == NULL ||
			texture->floor == NULL ||
			texture->ceiling == NULL)
			return (0);
	else
		return (1);
}

t_texture	*set_parameters(int fd)
{
	char		*line;
	t_texture	*app_texture;

	app_texture = malloc(sizeof(t_texture));
	if (!app_texture)
	{
		ft_putstr_fd(ERROR_MALLOC, 2);
		return (NULL);
	}
	line = get_next_line(fd);
	while (is_all_texture_set(app_texture) == 0 && line != NULL)
	{
		if (set_texture(line, app_texture) == -1)
			break ;
		line = get_next_line(fd);
	}
	if (is_all_texture_set(app_texture) == 0)
	{
		ft_putstr_fd(ERROR_MISSING_TEXTURE, 2);
		free_texture(app_texture);
	}
	if(is_all_texture_set(app_texture) == 1 && line == NULL)
	{
		ft_putstr_fd(ERROR_MISSING_MAP, 2);
		free_texture(app_texture);
	}
	while (line != NULL)
	{
		set_map(line, app_texture);
		line = get_next_line(fd);
	}
	close(fd);
	return (app_texture);
}

char *get_direction(char *line, int *i)
{
	char	*direction;

	direction = NULL;
	while (ft_is_sp_or_tab(line[*i]))
		(*i)++;
	while(!ft_is_sp_or_tab(line[*i]))
	{
		direction = ft_charjoin(direction, line[*i]);
		(*i)++;
	}
	while (line[*i] && ft_is_sp_or_tab(line[*i]))
		(*i)++;
	return (direction);
}


int	set_texture(char *line, t_texture *texture)
{
	int		i;
	char	*direction;

	i = 0;
	direction = get_direction(line, &i);
	if (!texture->north, ft_strcmp("NO", direction) == 0)
		texture->north = ft_strdup(&line[i]);
	else if (!texture->south, ft_strcmp("SO", direction) == 0)
		texture->south= ft_strdup(&line[i]);
	else if (!texture->east, ft_strcmp("EA", direction) == 0)
		texture->east = ft_strdup(&line[i]);
	else if (!texture->west, ft_strcmp("WE", direction) == 0)
		texture->west = ft_strdup(&line[i]);
	else if (!texture->floor, ft_strcmp("F", direction) == 0)
		texture->floor = ft_strdup(&line[i]);
	else if (!texture->ceiling, ft_strcmp("C", direction) == 0)
		texture->ceiling = ft_strdup(&line[i]);
	else
	{
		free(direction);
		return (-1);
	}
	free(direction);
	return (0);
}
