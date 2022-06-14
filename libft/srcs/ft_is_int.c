/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:58:42 by nburat-d          #+#    #+#             */
/*   Updated: 2022/02/15 15:11:49 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	del_zero(char *str, int i)
{
	int	len;

	len = ft_strlen(str);
	while (str[i] == '0' && str[i + 1] != '\0')
	{
		ft_memcpy(&str[i], &str[i + 1], ft_strlen(&str[i + 1]));
		str[len - 1] = 0;
		len--;
	}	
}

int	ft_is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	del_zero(str, i);
	while (str[i])
		if (ft_isdigit(str[i++]) == 0)
			return (0);
	if (ft_strlen(str) < 10)
		return (1);
	if (ft_strlen (str) > 11)
		return (0);
	if (ft_strlen (str) == 10)
		if (ft_strcmp("2147483647", str) < 0)
			return (0);
	if (ft_strlen(str) == 11)
		if (ft_strcmp("-2147483648", str) < 0)
			return (0);
	return (1);
}
