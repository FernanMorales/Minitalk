/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 14:05:07 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/13 14:05:10 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*tab;
	size_t		i;

	i = 0;
	if (size == 0)
		size = 1;
	tab = (char *)malloc(sizeof(tab) * size);
	if (!tab)
		return (NULL);
	while (i < size - 1)
	{
		tab[i] = '\0';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
