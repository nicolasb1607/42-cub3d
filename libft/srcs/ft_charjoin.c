/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:42:38 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/24 10:36:53 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*char_to_str(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_charjoin(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!c)
		return (NULL);
	if (str == NULL)
		return (char_to_str(c));
	new = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
		return (free(str), NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	new[i] = c;
	new[i + 1] = '\0';
	return (new);
}
