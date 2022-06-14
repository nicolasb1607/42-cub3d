/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:46:24 by nburat-d          #+#    #+#             */
/*   Updated: 2021/11/24 16:40:54 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Écrit La chaine de caractères ’s’ sur le file
descriptor donné, suivie d’un retour à la ligne.

#1. La chaine de caractères à écrire.
#2. Le file descriptor sur lequel écrire. */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
int main()
{
	ft_putendl_fd("hello", 1);
	return 0;
} */