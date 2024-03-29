/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:59:13 by slouham           #+#    #+#             */
/*   Updated: 2024/02/16 16:34:01 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h> // for test
# include <stdio.h> // for test

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char	*str);
char	*ft_strchr(char	*str, int c);
char	*ft_strjoin(char *chunk1, char *chunk2);

char	*get_next_line(int fd);

#endif
