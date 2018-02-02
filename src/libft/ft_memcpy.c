/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:14:48 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 14:43:12 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	if (n <= 0)
		return (dest);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
