/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 13:04:33 by fmorales          #+#    #+#             */
/*   Updated: 2014/02/09 14:10:04 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_realloc(void *ptr, size_t old, size_t n)
{
	void	*ptr2;

	if (!n && ptr)
		return ((void *)malloc(n));
	if (!ptr)
		return ((void *)malloc(n));
	if (!(ptr2 = (void *)malloc(n)))
		return (NULL);
	ft_memcpy(ptr2, ptr, old);
	ptr = NULL;
	return (ptr2);
}
