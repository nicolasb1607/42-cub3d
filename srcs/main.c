/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:27:26 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/07 11:30:42 by rpottier         ###   ########.fr       */
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
	else if (ac > 2)
		ft_putstr("Too many arguments\n");
	else
		ft_putstr("Missing arguments\n");
	return (0);
}
