/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:58:53 by slouham           #+#    #+#             */
/*   Updated: 2024/02/10 22:27:48 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char *get_next_line(int fd)
{
	int bytes_read;
	char *cup_buffer;

	cup_buffer = calloc(3 + 1, sizeof(char));
	if (cup_buffer == 0)
		return (0);
	bytes_read = read(fd, cup_buffer, 3);
	if (bytes_read <= 0)
		return (0);
	return (cup_buffer);
}

int main()
{
	int	fd;
	char	*next_line;
	int count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	next_line = get_next_line(fd);
	count++;
	printf("[%d]:%s\n", count, next_line);
	next_line = 0;

	close(fd);
	return (0);
}
