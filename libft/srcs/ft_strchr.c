/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:38:39 by nburat-d          #+#    #+#             */
/*   Updated: 2021/12/02 15:13:38 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (s[i])
	{
		if (s1[i] == (unsigned char) c)
			return (&s1[i]);
		i++;
	}
	if (s1[i] == (unsigned char) c)
		return (&s1[i]);
	return (NULL);
}
