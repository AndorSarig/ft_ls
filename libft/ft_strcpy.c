/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:47:02 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 13:51:29 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*source;
	int		i;

	i = 0;
	source = (char *)src;
	while (source[i] != '\0')
	{
		dst[i] = source[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
