/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:27:26 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/24 11:50:49 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (check_extension(av[1], ".cub") == 1)
		{
			if (launch_prgm(av[1]) != 0)
				return (1);
		}	
		else
			ft_putstr(ERROR_EXTENSION);
	}
	else
		ft_putstr("Too many arguments\n");
	return (0);
}
