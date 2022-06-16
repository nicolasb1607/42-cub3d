/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:24:27 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/01 09:06:02 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

/*
** get_next_line.c
*/

char	*get_next_line(int fd);
char	*read_line(char *fd_storage, int fd);
int		extract_str(char *fd_storage, char *line, char *buffer);
int		need_to_read(char *fd_storage);
void	ft_restruct_storage(char *fd_storage);

/*
** get_next_line_utils.c
*/

void	ft_bzero(void *s, size_t n);
char	*ft_realloc(char *str, int size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strcat(char *dest, char *src);
int		ft_len(const char *str);

#endif
