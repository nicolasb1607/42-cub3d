/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:36:15 by nburat-d          #+#    #+#             */
/*   Updated: 2021/12/01 08:48:51 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Itère sur la list lst et applique la fonction f au
contenu chaque élément.

#1 L’adresse du pointeur vers un élément.
#2. L’adresse de la fonction à appliquer.*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	while (lst != NULL)
	{
		current = lst;
		lst = lst->next;
		f(current->content);
	}
}
