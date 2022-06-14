/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:40:27 by nburat-d          #+#    #+#             */
/*   Updated: 2021/11/24 16:41:26 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applique la fonction f à chaque caractère de la
chaîne de caractères transmise comme argument, et
en passant son index comme premier argument. Chaque
caractère est transmis par adresse à f pour être
modifié si nécessaire.

#1. La chaine de caractères sur laquelle itérer.
#2. La fonction à appliquer à chaque caractère. */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = -1;
	if (s != NULL && f != NULL)
		while (s[++i])
			f(i, &s[i]);
	return ;
}
