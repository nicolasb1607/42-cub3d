/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:24:31 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/21 16:09:52 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_map_size(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if(ft_strlen(line) > map->width)
			map->width = ft_strlen(line);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

char	*collect_data_from_line(char *line, char *content)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_allowed_char(line[i]))
		{
			free(content);
			return (NULL);
		}
		else if (ft_is_space(line[i]))
			j++;
		else
			content[j] = line[i];
		i++;
	}
	return (content);
}


void	fill_map(t_file *file, t_map *map)
{
	int line;
	int	i;

	i = 0;
	
	line = get_next_line(file->fd);
	while (line != NULL)
	{
		map->content[i] = collect_data_from_line(line, map->content[i]);
	//	if (map->content[i] == NULL)
			//free toute la map et la line
		free(line);
		line = get_next_line(file->fd);
	}
	
}

int	get_map_content(t_file *file, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	file->fd = open(file->name, O_RDONLY);
	if(file->fd < 0)
	{
		ft_putstr_fd(ERROR_OPEN_FILE, 2);
		return (-1);
	}
	while(i < file->map_index - 1)
	{
		line = get_next_line(file->fd);
		free(line);
		i++;
	}
	map->content = ft_calloc(map->height + 1, sizeof(char *));
	if(!map->content)
	{
		ft_putstr_fd(ERROR_MALLOC, 2);
		return (-1);
	}
	i = 0;
	while (i < map->height)
	{
		map->content[i] = ft_calloc(map->width + 1, sizeof(char));
		ft_memset(map->content[i], '0', map->width);
		if(!map->content[i])
		{ //FREE LE TABLEAU COMPLET
			ft_putstr_fd(ERROR_MALLOC, 2);
			return (-1);
		}
		i++;
	}
	
	
	
}


t_map	*set_map(t_file *file)
{
	t_map	*map;
	char	*line;
	

	line = get_next_line(file->fd);
	while (line != NULL && line[0] == '\n')
	{
		file->map_index++;
		free(line);
		line = get_next_line(file->fd);
	}
	if (line == NULL)
	{
		ft_putstr_fd(ERROR_MISSING_MAP, 2);
		close(file->fd);
		return (NULL);
	}
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	 	return (NULL);
	get_map_size(file->fd, map);
	get_map_content(file->fd, map);
	
/*
** determiner la taille de la map lors du premier passage
** malloc 2d array
*/

}