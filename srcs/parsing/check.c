/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:56:47 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/11 08:54:52 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_extension(char *file_name, char *extension)
{
	int	i;

	i = 0;
	while (file_name[i] && file_name[i] != '.')
		i++;
	if (file_name[i] && ft_strcmp(&file_name[i], extension) == 0)
		return (1);
	return (0);
}

int	check_map(t_map *map)
{
	if (!check_map_size(map))
	{
		ft_putstr_fd(ERROR_MAP_SIZE, 2);
		return (FALSE);
	}
	if (!check_player(map))
	{
		ft_putstr_fd(ERROR_PLAYER, 2);
		return (FALSE);
	}
	if (!check_closed_map(map))
	{
		ft_putstr_fd(ERROR_MAP_NOT_CLOSED, 2);
		return (FALSE);
	}
	return (TRUE);
}

int	check_map_size(t_map *map)
{
	if (map->height < 3 || map->width < 3)
		return (0);
	return (1);
}

int	check_player(t_map *map)
{
	int	i;
	int	j;
	int	player_presence;

	player_presence = FALSE;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (is_a_player(map->content[i][j]))
			{
				if (player_presence == TRUE)
					return (FALSE);
				else
					player_presence = TRUE;
			}
			j++;
		}
		i++;
	}	
	return (player_presence);
}

int	is_a_player(char c)
{
	if (c == 'N'
		|| c == 'S'
		|| c == 'W'
		|| c == 'E')
		return (TRUE);
	else
		return (FALSE);
}
