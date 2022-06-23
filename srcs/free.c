/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:09:14 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/23 09:49:49 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_texture(t_texture **texture)
{
	if ((*texture)->north)
		free((*texture)->north);
	if ((*texture)->south)
		free((*texture)->south);
	if ((*texture)->west)
		free((*texture)->west);
	if ((*texture)->east)
		free((*texture)->east);
	if ((*texture)->floor)
		free((*texture)->floor);
	if ((*texture)->ceiling)
		free((*texture)->ceiling);
	free((*texture));
	*texture = NULL;
}

void	free_map(t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map->content[i]);
		i++;
	}
	free(map->content);
	free(map);
}


t_map	*alloc_map_content(t_map *map)
{
	int	i;

	map->content = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->content)
	{
		ft_putstr_fd(ERROR_MALLOC, 2);
		return (NULL);
	}
	i = 0;
	while (i < map->height)
	{
		map->content[i] = ft_calloc(map->width + 1, sizeof(char));
		if (!map->content[i])
		{
			free_map(map, i);
			ft_putstr_fd(ERROR_MALLOC, 2);
			return (NULL);
		}
		ft_memset_char_bis(map->content[i], '1', map->width);
		i++;
	}
	return (map);
}
