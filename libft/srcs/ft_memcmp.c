/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:38:24 by nburat-d          #+#    #+#             */
/*   Updated: 2021/11/24 16:40:28 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  memcmp()  function compares the first n bytes (each interpreted as
unsigned char) of the memory areas s1 and s2.

The memcmp() function returns  an  integer  less  than,  equal  to,  or
greater than zero if the first n bytes of s1 is found, respectively, to
be less than, to match, or be greater than the first n bytes of s2.

For a nonzero return value, the sign is determined by the sign  of  the
difference  between  the  first  pair of bytes (interpreted as unsigned
char) that differ in s1 and s2.

If n is zero, the return value is zero.*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;
	int				pos;

	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	pos = 0;
	if (n == 0)
		return (0);
	while (ptrs1[pos] == ptrs2[pos] && n - 1 > 0 && (ptrs1 || ptrs2))
	{
		pos++;
		n--;
	}
	return (ptrs1[pos] - ptrs2[pos]);
}
