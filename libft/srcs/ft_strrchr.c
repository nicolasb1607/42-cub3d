/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:39:09 by nburat-d          #+#    #+#             */
/*   Updated: 2021/11/30 11:11:17 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pos;

	i = 0;
	pos = NULL;
	if ((ft_isascii(c) == 0))
		return ((char *)&s[i]);
	if (c == '\0')
	{
		while (s[i] != '\0')
			i++;
		pos = (char *)&s[i];
	}
	else
	{
		i = -1;
		while (s[++i])
			if (s[i] == c)
				pos = (char *)&s[i];
	}
	return (pos);
}
