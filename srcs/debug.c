/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:29:41 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/20 15:31:34 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void print_param(t_texture *app_texture)
{
	printf("NO : [%s]\n", app_texture->north);
	printf("SO : [%s]\n", app_texture->south);
	printf("WE : [%s]\n", app_texture->west);
	printf("EA : [%s]\n", app_texture->east);
	printf("F  : [%s]\n", app_texture->floor);
	printf("C  : [%s]\n", app_texture->ceiling);
}