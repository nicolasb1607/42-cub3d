/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:16:40 by nburat-d          #+#    #+#             */
/*   Updated: 2022/02/23 16:17:45 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelone(t_dlist *lst, void (*del)(void*))
{
	t_dlist	*tmp;

	tmp = lst;
	if (lst != NULL && del != NULL)
	{
		lst->next->prev = tmp->prev;
		lst->prev->next = tmp->next;
		(*del)(lst->content);
		free(lst);
	}
}
