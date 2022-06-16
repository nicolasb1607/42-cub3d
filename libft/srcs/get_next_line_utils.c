/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:24:19 by rpottier          #+#    #+#             */
/*   Updated: 2021/12/06 10:22:53 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(const char *str)
{
	int	length;

	length = 0;
	if (str)
	{
		while (str[length])
		{
			length++;
		}
	}
	return (length);
}

char	*ft_realloc(char *str, int size)
{
	char	*new_str;

	new_str = malloc(sizeof(*new_str) * size + 1);
	ft_bzero(new_str, size);
	if (str)
	{
		ft_strlcpy(new_str, str, size);
		free(str);
	}
	return (new_str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_length;

	i = 0;
	src_length = 0;
	while (src[src_length])
		src_length++;
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_length);
}

/* Retourne le point d'arret de src*/
int	ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && src[j] != '\n')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (src[j] && src[j] == '\n')
		dest[i] = src[j];
	i++;
	dest[i] = '\0';
	return (j);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
