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

void	print_hex(unsigned char *addr, size_t size)
{
	int i;

	i = 0;
	ft_printf("\n %d bytes\n00 - ", size);
	while (size)
	{
		ft_printf("%.2X ", *addr);
		addr++;
		size--;
		i++;
		if (!(i % 10))
			ft_printf("\n%d - ", i);
	}
	ft_printf("\n");
}
