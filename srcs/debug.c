/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:29:41 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/08 14:58:06 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_param(t_texture *app_texture)
{
	printf("NO : [%s]\n", app_texture->north);
	printf("SO : [%s]\n", app_texture->south);
	printf("WE : [%s]\n", app_texture->west);
	printf("EA : [%s]\n", app_texture->east);
	printf("F  : [%s]\n", app_texture->floor);
	printf("C  : [%s]\n", app_texture->ceiling);
}

void	print_rgb_param(char *F_OR_C, t_color *color)
{
	printf("%s R=%d, G=%d, B=%d\n", F_OR_C, color->red,
		color->green, color->blue);
}

void	print_2d_array(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			printf("%c ", array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

double	ft_abs_double(double nb)
{
	if (nb < 0)
		nb = nb * (-1.0);
	return (nb);
}
