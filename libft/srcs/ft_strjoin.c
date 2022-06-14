/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:38:47 by nburat-d          #+#    #+#             */
/*   Updated: 2021/11/29 15:44:41 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Alloue (avec malloc(3)) et retourne une nouvelle
chaine, résultat de la concaténation de s1 et s2.

La nouvelle chaine de caractères. NULL si
l’allocation échoue.

#1. La chaine de caractères préfixe.
#2. La chaine de caractères suffixe. */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		catlen;
	char	*strcat;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	catlen = ft_strlen(s1) + ft_strlen(s2);
	strcat = malloc((catlen + 1) * sizeof(char));
	if (!strcat)
		return (NULL);
	if (s1 != NULL)
		while (s1[++i])
			strcat[++j] = s1[i];
	i = -1;
	if (s2 != NULL)
	{
		while (s2[++i] && s2 != NULL)
			strcat[++j] = s2[i];
	}
	strcat[++j] = '\0';
	return (strcat);
}
