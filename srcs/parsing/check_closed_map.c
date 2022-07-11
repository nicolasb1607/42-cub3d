/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:35:43 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/11 08:44:29 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_closed_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->content[i][j] == '0' || is_a_player(map->content[i][j]))
			{
				if (!check_up_wall(map, i, j))
					return (FALSE);
				if (!check_down_wall(map, i, j))
					return (FALSE);
				if (!check_left_wall(map, i, j))
					return (FALSE);
				if (!check_right_wall(map, i, j))
					return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	check_up_wall(t_map *map, int i, int j)
{
	if (i == 0)
		return (FALSE);
	i--;
	while (i >= 0)
	{
		if (map->content[i][j] == '1')
			return (TRUE);
		else if (map->content[i][j] == '3')
			return (FALSE);
		i--;
	}
	return (FALSE);
}

int	check_down_wall(t_map *map, int i, int j)
{
	if (i == map->height - 1)
		return (FALSE);
	i++;
	while (i <= map->height - 1)
	{
		if (map->content[i][j] == '1')
			return (TRUE);
		else if (map->content[i][j] == '3')
			return (FALSE);
		i++;
	}
	return (FALSE);
}

int	check_left_wall(t_map *map, int i, int j)
{
	if (j == 0)
		return (FALSE);
	j--;
	while (j >= 0)
	{
		if (map->content[i][j] == '1')
			return (TRUE);
		else if (map->content[i][j] == '3')
			return (FALSE);
		j--;
	}
	return (FALSE);
}

int	check_right_wall(t_map *map, int i, int j)
{
	if (j == map->width - 1)
		return (FALSE);
	j++;
	while (j <= map->width - 1)
	{
		if (map->content[i][j] == '1')
			return (TRUE);
		else if (map->content[i][j] == '3')
			return (FALSE);
		j++;
	}
	return (FALSE);
}
