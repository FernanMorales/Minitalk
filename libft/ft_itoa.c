/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 13:52:24 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/13 13:52:27 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_index(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = (n + 1) * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_limit(int n, int i)
{
	int		nb;
	char	*tab;

	tab = ft_strnew(i + 1);
	nb = i - 1;
	n = n + 5;
	n = (-1) * n;
	tab[0] = '-';
	i--;
	while (n > 0)
	{
		tab[i] = '0' + n % 10;
		n = n / 10;
		i--;
	}
	tab[nb] = '8';
	return (tab);
}

char		*ft_itoa(int n)
{
	char	*tab;
	int		i;

	i = ft_index(n);
	tab = ft_strnew(i + 1);
	if (!tab)
		return (NULL);
	if (n == -2147483648)
		return (ft_limit(n, i));
	if (n < 0)
	{
		n = n * -1;
		tab[0] = '-';
	}
	i--;
	if (n == 0)
		tab[0] = '0';
	while (n > 0)
	{
		tab[i] = '0' + n % 10;
		n = n / 10;
		i--;
	}
	return (tab);
}
