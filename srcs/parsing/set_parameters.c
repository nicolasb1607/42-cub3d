/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:25:19 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/21 13:51:40 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_data	*set_parameters(t_file	*file)
{
	t_data	*data;

	file->fd = open(file->name, O_RDONLY);
	if (file->fd == -1)
	{
		ft_putstr_fd(ERROR_OPEN_FILE, 2);
		return (NULL);
	}
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
		
	data->texture = set_texture(file);
	if (!data->texture)
	{
		// free data
	}
	data->map = set_map(file);
	if (!data->map)
	{
		// free data->texture
		// free data
	}
	
}
