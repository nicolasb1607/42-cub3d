/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:24:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/17 13:06:16 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
** Apres avoir copie la ligne dans LINE(dans la fonction extract),
** cette fonction redecale tout vers la gauche
*/

void	ft_restruct_storage(char *fd_storage)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (fd_storage[i] && fd_storage[i] != '\n')
		i++;
	i++;
	while (fd_storage[i])
	{
		fd_storage[j] = fd_storage[i];
		i++;
		j++;
	}
	fd_storage[j] = fd_storage[i];
	j++;
	while (fd_storage[j])
	{
		fd_storage[j] = '\0';
		j++;
	}
}

/*
** Cette extrait la ligne du buffer, remplit line avec le contenu de fd_storage
** si besoin et le cas echant remplit ft_storage avec le contenu de buffer non
** utilise
*/
int	extract_str(char *fd_storage, char *line, char *buffer)
{
	int	i;
	int	j;
	int	start;

	i = -1;
	if (fd_storage[0] != '\0')
	{
		ft_strcat(line, fd_storage);
		ft_restruct_storage(fd_storage);
	}
	start = ft_len(line);
	if (start != 0)
		if (line[start - 1] == '\n')
			return (1);
	while (buffer[++i] && buffer[i] != '\n')
		line[start + i] = buffer[i];
	if (buffer[i] == '\n')
	{
		line[start + i] = buffer[i];
		j = 0;
		while (buffer[++i])
			fd_storage[j++] = buffer[i];
		return (1);
	}
	return (0);
}

/* Check la presence d'un \n dans la reserve
** pour savoir si l'on doit faire appel a read
*/

int	need_to_read(char *fd_storage)
{
	int	i;

	if (!fd_storage)
		return (1);
	i = 0;
	while (fd_storage[i])
	{
		if (fd_storage[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*read_line(char *fd_storage, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	int		read_ret;
	int		line_size;
	int		end_of_line;

	end_of_line = 0;
	read_ret = 1;
	line = NULL;
	while (read_ret > 0 && !end_of_line)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		if (need_to_read(fd_storage))
			read_ret = read(fd, buffer, BUFFER_SIZE);
		line_size = ft_len(fd_storage) + ft_len(buffer) + (ft_len(line) + 1);
		if (line_size == 1)
			return (NULL);
		line = ft_realloc(line, sizeof(*line) * line_size);
		if (!line)
			return (NULL);
		end_of_line = extract_str(fd_storage, line, buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	fd_storage[2048][BUFFER_SIZE + 1];
	char		*line;

	if (fd >= 0 && BUFFER_SIZE > 0)
		line = read_line(fd_storage[fd], fd);
	else
		return (NULL);
	return (line);
}
