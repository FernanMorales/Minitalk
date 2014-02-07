/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 00:05:26 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/29 00:05:32 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_length(char const *s1, char const *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	return (i + j);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	int		i;
	int		j;
	char	*tab;

	if (s1 != NULL && s2 != NULL)
	{
		l = ft_length(s1, s2);
		tab = (char *)malloc(sizeof(char *) * (l + 1));
		i = 0;
		j = 0;
		while (s1[i] != '\0')
		{
			tab[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			tab[i++] = s2[j++];
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
