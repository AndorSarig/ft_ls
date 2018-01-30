/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:57:45 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 14:44:06 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (*big && len)
	{
		if (*big == little[i])
			i++;
		else
			i = 0;
		if (little[i] == '\0')
			return ((char *)(big - i + 1));
		big++;
		len--;
	}
	return (NULL);
}
