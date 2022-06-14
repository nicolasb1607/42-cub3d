/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:38:20 by nburat-d          #+#    #+#             */
/*   Updated: 2021/11/30 14:11:01 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  memchr()  function  scans  the  initial n bytes of the memory area
       pointed to by s for the first instance of c. Both c and the bytes of
       the memory area pointed to by s are interpreted as unsigned char.

The  memchr()  and memrchr() functions return a pointer to the matching 
byte or NULL if the character does not occur in the given memory area.	   
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ptrc;
	unsigned char	*ptrs;
	size_t			pos;

	ptrc = (unsigned char) c;
	ptrs = (unsigned char *)s;
	pos = 0;
	if (n == 0)
		return (NULL);
	while (pos < n)
	{
		if (ptrs[pos] == ptrc)
			return (&ptrs[pos]);
		pos++;
	}	
	return (NULL);
}
