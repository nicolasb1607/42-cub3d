/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:56:47 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/22 16:43:36 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"

int	check_extension(char *file_name, char *extension)
{
	int	i;

	i = 0;
	while (file_name[i] && file_name[i] != '.')
		i++;
	if(file_name[i] && ft_strcmp(&file_name[i], extension) == 0)
		return (1);
	return (0);
}

int	check_map(t_map *map)
{
	print_2d_array(map->content);
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

int check_map_size(t_map *map)
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
	if (c == 'N' ||
		c == 'S' ||
		c == 'W' ||
		c == 'E')
		return (TRUE);
	else
		return (FALSE);
}

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
				{
					printf("up\n");
					return (FALSE);
				}
				if (!check_down_wall(map, i, j))
				{
					printf("down\n");
					return (FALSE);
				}
				if (!check_left_wall(map, i, j))
				{
					printf("left\n");
					return (FALSE);
				}
				if (!check_right_wall(map, i, j))
				{
					printf("right\n");
					return (FALSE);
				}
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	check_up_wall(t_map *map, int i, int j)
{
	printf("i = %d,  j = %d\n", i, j);
	if (i == 0)
		return (FALSE);
	i--;
	while (i >= 0)
	{
		printf("i = %d,  j = %d\n", i, j);
		if (map->content[i][j] == '1')
			return (TRUE);
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
		j++;
	}
	return (FALSE);
}
