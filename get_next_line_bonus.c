/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:13:41 by slouham           #+#    #+#             */
/*   Updated: 2024/02/16 16:49:52 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_read(int fd, char	*string)
{
	char	*chunk;
	ssize_t	rbts;

	chunk = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	rbts = 1;
	while (!ft_strchr(string, '\n') && rbts != 0)
	{
		rbts = read(fd, chunk, BUFFER_SIZE);
		if (rbts == -1)
		{
			free(chunk);
			return (NULL);
		}
		chunk[rbts] = 0;
		string = ft_strjoin(string, chunk);
	}
	free(chunk);
	return (string);
}

char	*get_line(char *buffer)
{
	char	*line2;
	size_t	n;

	n = 0;
	if (!buffer[n])
		return (NULL);
	while (buffer[n] && buffer[n] != '\n')
		n++;
	line2 = (char *)malloc((n + 2) * sizeof(char));
	if (!line2)
		return (NULL);
	n = 0;
	while (buffer[n] && buffer[n] != '\n')
	{
		line2[n] = buffer[n];
		n++;
	}
	if (buffer[n] == '\n')
		line2[n++] = '\n';
	line2[n] = 0;
	return (line2);
}

char	*get_rest(char *buffer)
{
	char	*new_part;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	size = ft_strlen(&buffer[i]);
	new_part = (char *)malloc(size + 1);
	j = 0;
	while (buffer[i])
		new_part[j++] = buffer[i++];
	new_part[j] = 0;
	free(buffer);
	return (new_part);
}

char	*get_next_line(int fd)
{
	static char		*rest[__FD_SETSIZE];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > __FD_SETSIZE)
		return (NULL);
	rest[fd] = get_read(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = get_line(rest[fd]);
	rest[fd] = get_rest(rest[fd]);
	return (line);
}
