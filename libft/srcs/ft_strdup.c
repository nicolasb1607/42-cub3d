/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:38:43 by nburat-d          #+#    #+#             */
/*   Updated: 2021/11/29 12:53:05 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 The strdup() function returns a pointer to a new string which is a duplicate of
the string s.  Memory for the new string is obtained with malloc(3), and can be 
freed with free(3).

On success, the strdup() function returns a pointer to the duplicated string.  
It  returns  NULL  if  insufficient  memory  was available, with errno set to 
indicate the cause of the error.
*/
char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*dup;

	len = ft_strlen(s);
	i = 0;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
