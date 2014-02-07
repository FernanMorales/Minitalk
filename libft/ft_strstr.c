/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:47:43 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/29 21:47:46 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	nb;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			nb = i;
			while (s1[i] == s2[j++] && s1[i] != '\0')
			{
				i++;
				if (s2[j] == '\0')
					return ((char *)&s1[nb]);
			}
			j = 0;
			i = nb;
		}
		i++;
	}
	return (NULL);
}
