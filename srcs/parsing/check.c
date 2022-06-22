/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:56:47 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/22 14:54:29 by rpottier         ###   ########.fr       */
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

int	check_map(t_map *map);
{

	/*
	check des zero

	*/
	
}


