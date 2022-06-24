/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:27:42 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/24 16:01:35 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_rgb_format(char *str_color)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = ft_split(str_color, ',');
	if (ft_tablen(splitted) != 3)
		return(free_tab(splitted), FALSE);
	while(splitted[i])
	{
		if(ft_is_int(splitted[i]) && ft_atoi(splitted[i]) <= 255 && ft_atoi(splitted[i]) >= 0)
			i++;
		else
			return (free_tab(splitted), FALSE);
	}
	return (free_tab(splitted), TRUE);
}

int	assign_color(char *str_color, t_color *color)
{	
	char	**rgb_tab;
	
	if (!is_rgb_format(str_color))
	{
		ft_putstr_fd(ERROR_COLOR_FORMAT, 2);		
		return (-1);
	}
	rgb_tab = ft_split(str_color, ',');
	color->red = ft_atoi(rgb_tab[0]);
	color->green = ft_atoi(rgb_tab[1]);
	color->blue = ft_atoi(rgb_tab[2]);
	return(free_tab(rgb_tab), 0);
}

int	set_color(t_data *data)
{
	if(!data)
		return(-1);
	data->floor_color = ft_calloc(1, sizeof(t_color));
	if(!data->floor_color)
		return(ft_putstr_fd(ERROR_MALLOC, 2), -1);
	if (assign_color(data->texture->floor, data->floor_color) != 0)
	{
		free_color(data->floor_color);
		return (-1);
	}
	data->ceiling_color = ft_calloc(1, sizeof(t_color));
	if(!data->ceiling_color)
		return(ft_putstr_fd(ERROR_MALLOC, 2), -1);
	if (assign_color(data->texture->floor, data->ceiling_color) != 0)
	{
		free_color(data->floor_color);
		free_color(data->ceiling_color);
		return (-1);
	}
	return (0);
}