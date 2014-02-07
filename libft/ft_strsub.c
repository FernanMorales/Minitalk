/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 14:06:30 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/22 15:54:56 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tab;
	size_t		i;

	if (s != NULL)
	{
		tab = (char *)malloc(sizeof(tab) * (len + 1));
		i = 0;
		while (i < len)
		{
			tab[i] = s[start + i];
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
