/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:03:25 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/17 14:04:49 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"parsing.h"

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
	while (line != NULL)
	{
		set_texture_param(line, app_texture);
		line = get_next_line(fd);
	}
	close(fd);
	return (app_texture);
}

void	set_texture_param(char *line, t_texture *texture)
{
	int		i;
	char	*direction;

	i = 0;
	direction = NULL;
	while (line[i] && (line[i] == ' ' || line[i] == 9))
		i++;
	while(line[i] && (line[i] != ' ' || line[i] != 9))
	{
		direction = ft_charjoin(direction, line[i]);
		i++;
	}
	if (ft_strcmp("NO", direction) == 0)
		texture->north = 
	if (ft_strcmp("SO", direction) == 0)
		texture->south= ft_strdup(direction);
	if (ft_strcmp("EA", direction) == 0)
		texture->east = ft_strdup(direction);
	if (ft_strcmp("WE", direction) == 0)
		texture->west = ft_strdup(direction);
	if (ft_strcmp("F", direction) == 0)
		texture->floor = ft_strdup(direction);
	if (ft_strcmp("C", direction) == 0)
		texture->north = ft_strdup(direction);
	
}