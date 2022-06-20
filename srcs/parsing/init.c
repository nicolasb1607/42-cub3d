/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:52:50 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/20 16:08:23 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_texture	*init_texture(void)
{
	t_texture *texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
	{
		ft_putstr_fd(ERROR_MALLOC, 2);
		return (NULL);
	}
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->floor = NULL;
	texture->ceiling = NULL;
	return (texture);
}
