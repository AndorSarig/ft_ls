/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:55:05 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 13:56:38 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*source;

	i = 0;
	j = 0;
	source = (char *)s2;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && j != n)
	{
		s1[i] = source[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
