/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:33:57 by ktlili            #+#    #+#             */
/*   Updated: 2018/10/12 23:33:42 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int j;
	int sign;
	int ret;

	i = 0;
	j = 0;
	sign = 1;
	while ((str[i] == 32) | (str[i] == '\t') | (str[i] == '\r')
			| (str[i] == '\n') | (str[i] == '\v') | (str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (-(str[i] - 44));
		i++;
	}
	ret = 0;
	while (str[i] > 47 && str[i] < 58 && ret < 2147483647 && ret > -2147483648)
	{
		ret = ret * 10 + (str[i] - 48);
		if (ret < 0) {
			return -1;
		}
		i++;
		j++;
	}
	return (ret * sign);
}
