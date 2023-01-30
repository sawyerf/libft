/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalldigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:46:24 by ktlili            #+#    #+#             */
/*   Updated: 2021/04/07 15:01:20 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalldigit(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	ft_isint(char *s)
{
	if (*s == '\0')
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	if (ft_strlen(s) > 10)
		return (0);
	return (ft_isalldigit(s));
}
