/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:15:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/17 13:56:04 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_prgm.h"

void	launch_prgm(char *map_file)
{
	int		fd; 
	t_texture *app_texture;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(ERROR_OPEN_FILE, 2);
		return ;
	}
	set_parameters(fd);
}