/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:01:32 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 19:03:57 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		n_len;

	n_len = ft_strlen(little);
	if (ft_strcmp(big, little) == 0)
		return ((char *)big);
	if (little[0] == '\0')
		return ((char *)big);
	while (*big)
	{
		if (ft_strncmp(big, little, n_len) == 0
				&& ft_strlen(big) >= (unsigned long)n_len)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
