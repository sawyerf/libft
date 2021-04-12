/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:17:08 by apeyret           #+#    #+#             */
/*   Updated: 2021/04/07 15:03:23 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnew(size_t size)
{
	char	**tab;
	size_t	count;

	count = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (count < size + 1)
	{
		tab[count] = NULL;
		count++;
	}
	return (tab);
}

char	**ft_tabadd(char **tab, char *s)
{
	int len;

	len = ft_tablen(tab);
	tab[len] = s;
	tab[len + 1] = NULL;
	return (tab);
}
