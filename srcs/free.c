/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:09:14 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/20 17:18:26 by nburat-d         ###   ########.fr       */
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