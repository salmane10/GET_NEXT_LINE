/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:58:53 by slouham           #+#    #+#             */
/*   Updated: 2024/02/09 11:59:04 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char *get_next_line(int fd)
{
	static int a = 10;
	int b = 5;
	a = b;
	printf("%d", a);
}