/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:36:29 by nburat-d          #+#    #+#             */
/*   Updated: 2021/11/30 14:01:38 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Alloue (avec malloc(3)) et retourne une copie de
la chaine ’s1’, sans les caractères spécifiés
dans ’set’ au début et à la fin de la chaine de
caractères.

Retourne la chaine de caractères trimmée. NULL si
l’allocation échoue.

#1. La chaine de caractères à trimmer.
#2. Le set de reference de caractères à trimmer. */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	j = ft_strlen(s1) - 1;
	while (s1[j] && ft_strchr(set, s1[j]))
		j--;
	str = ft_substr((char *)s1, 0, j + 1);
	return (str);
}
