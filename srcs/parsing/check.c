/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:56:47 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/16 16:46:28 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"



int	check_extension(char *file_name, char *extension)
{
	int	i;

	i = 0;
	while (file_name[i] && file_name[i] != '.')
		i++;
	if(file_name[i] && ft_strcmp(&file_name[i], extension) == 0)
		return (1);
	return (0);
}