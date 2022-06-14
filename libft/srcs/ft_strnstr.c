/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:39:05 by nburat-d          #+#    #+#             */
/*   Updated: 2021/11/26 14:22:22 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strnstr() function locates the first occurrence of the null-termi‐
nated string little in the string big, where not more than len characters 
are searched.  Characters that appear after a Null-terminated character are not
searched.  Since the strnstr() function is a FreeBSD specific API, it
should only be used when portability is not a concern.

If little is an empty string, big is returned; if little occurs nowhere
in big, NULL is returned; otherwise a pointer to the first character of 
the first occurrence of little is returned. 
*/
char	*ft_strnstr(const char *to_search, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)&to_search[i]);
	if (len == 0)
		return (NULL);
	while (to_search[i] && i < len)
	{
		j = 0;
		while (to_search[i + j] == to_find[j] && (i + j) < len)
		{
			if (j == (size_t) ft_strlen(to_find) - 1)
				return ((char *)&to_search[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
