/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:24:31 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/21 14:18:35 by rpottier         ###   ########.fr       */
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
	close(file->fd);
	open()
	
/*
** determiner la taille de la map lors du premier passage
** malloc 2d array
*/

}