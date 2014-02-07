/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 06:04:38 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/29 09:52:00 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*us1;
	const unsigned char	*us2;
	size_t				i;

	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i < n)
	{
		if (us1[i] < us2[i])
			return (us1[i] - us2[i]);
		else if (us1[i] > us2[i])
			return (us1[i] - us2[i]);
		else if (!us1[i])
			return (0);
		++i;
	}
	return (0);
}
