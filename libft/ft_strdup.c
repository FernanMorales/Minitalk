/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:30:40 by fmorales          #+#    #+#             */
/*   Updated: 2013/11/26 01:18:40 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*c;

	c = (char*) malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (c != 0)
	{
		ft_strcpy(c, src);
		return (c);
	}
	else
		return (0);
}
