/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:25:32 by slouham           #+#    #+#             */
/*   Updated: 2024/02/16 16:46:26 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (&str[i]);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *chunk1, char *chunk2)
{
	size_t	i;
	size_t	j;
	char	*buffer;

	if (!chunk1)
	{
		chunk1 = (char *)malloc(1 * sizeof (char));
		*chunk1 = '\0';
	}
	if (!chunk1 || !chunk2)
		return (NULL);
	buffer = (char *)malloc((ft_strlen(chunk1) + ft_strlen(chunk2) + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (chunk1[i])
		buffer[j++] = chunk1[i++];
	i = 0;
	while (chunk2[i])
		buffer[j++] = chunk2[i++];
	buffer[j] = 0;
	free(chunk1);
	return (buffer);
}
