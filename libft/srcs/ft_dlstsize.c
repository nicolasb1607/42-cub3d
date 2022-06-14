/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:25:34 by nburat-d          #+#    #+#             */
/*   Updated: 2022/02/23 14:34:18 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Compte le nombre d’éléments de la liste.

#1. Le début de la liste.*/
int	ft_dlstsize(t_dlist *lst)
{
	t_dlist	*current;
	int		size;

	current = lst;
	size = 0;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}
