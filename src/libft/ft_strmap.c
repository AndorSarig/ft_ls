/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:54:10 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 14:22:32 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fstr;
	int		i;
	int		j;

	if (s && f)
	{
		i = 0;
		j = ft_strlen((char *)s);
		if (!(fstr = (char *)ft_memalloc(j * sizeof(char) + 1)))
			return (NULL);
		while (s[i] != '\0')
		{
			fstr[i] = f(s[i]);
			i++;
		}
		fstr[i] = '\0';
		return (fstr);
	}
	return (NULL);
}
