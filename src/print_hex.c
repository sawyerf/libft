/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 20:33:57 by apeyret           #+#    #+#             */
/*   Updated: 2021/04/07 15:02:35 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

#define MAX_HEX 10//include

void	print_hex(unsigned char *addr, size_t size)
{
	int i;
	char s[MAX_HEX + 1];

	i = 0;
	printf("\n %ld bytes\n00 - ", size);
	while (size)
	{
		printf("%.02X ", *addr);
		if (ft_isprint(*addr))
			s[i % MAX_HEX] = *addr;
		else
			s[i % MAX_HEX] = '.';
		addr++;
		size--;
		i++;
		if (!(i % MAX_HEX))
		{
			s[MAX_HEX] = 0;
			printf(" |%s|\n%.2d - ", s, i);
		}
	}
	if ((i % MAX_HEX))
	{
		s[i % MAX_HEX] = 0;
		printf(" |%s|\n", s);
	}
	printf("\n");
}
