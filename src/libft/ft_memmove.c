/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:16:15 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 13:45:41 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)dst;
	tmp2 = (char *)src;
	if (tmp2 < tmp1)
		while (len--)
			tmp1[len] = tmp2[len];
	else
		ft_memcpy(tmp1, tmp2, len);
	return (tmp1);
}
