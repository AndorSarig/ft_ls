/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:46:04 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 14:26:31 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	bgn;
	char	*sstr;

	i = 0;
	bgn = (size_t)start;
	if (s == NULL)
		return (NULL);
	if (bgn > ft_strlen(s))
		return (NULL);
	if ((sstr = (char *)ft_memalloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len && s[bgn] != '\0')
	{
		sstr[i] = (char)s[bgn];
		bgn++;
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}
