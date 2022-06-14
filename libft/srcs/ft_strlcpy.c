/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:38:54 by nburat-d          #+#    #+#             */
/*   Updated: 2021/11/30 12:51:25 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strlcpy() and strlcat() functions copy and concatenate strings respectively.
They are designed to be safer, more consistent, and less error prone
replacements for strncpy(3) and strncat(3).  Unlike those functions, strlcpy()
and strlcat() take the full
size of the buffer (not just the length) and guarantee to NUL-terminate 
the result (as long as size is larger than 0 or, in the
case of strlcat(), as long as there is at least one byte free in dst).  
Note that a byte for the NUL should be included in size.
Also note that strlcpy() and strlcat() only operate on true “C” strings. 
This means that for strlcpy() src must be NUL-terminated and for strlcat()
both src and dst must be NUL-terminated.

The strlcpy() function copies up to size - 1 characters from the NUL-terminated
string src to dst, NUL-terminating the result.*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	long unsigned int	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen((char *) src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen((char *) src));
}
