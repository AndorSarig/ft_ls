/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:11:06 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 17:12:47 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	tmp1 = (char *)dst;
	tmp2 = (char *)src;
	while (i < n)
	{
		if ((tmp1[i] = tmp2[i]) == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
