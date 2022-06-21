/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:15:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/21 13:50:18 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_prgm.h"

void	launch_prgm(char *map_file)
{
	t_file	file;
	t_data	*data;
//	t_texture *app_texture;

	//app_texture = NULL;
	file.name = map_file;
	file.map_index = 0;
	file.fd = -1;
	data = set_parameters(&file);
	if (!data)
	{
		// error
	}
	//print_param(app_texture);
}
