/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:16:52 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 14:28:59 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtrim_exec(char const *s)
{
	int		first;
	int		last;
	char	*ts;
	int		i;

	i = 0;
	while ((s[i] != 0) && (s[i] == 9 || s[i] == 10 || s[i] == 32))
		i++;
	first = i;
	last = i;
	while (s[i] != 0)
	{
		if (s[i] != 9 && s[i] != 10 && s[i] != 32)
			last = i;
		i++;
	}
	i = 0;
	ts = ft_memalloc(sizeof(char) * (last - first + 2));
	if (ts == 0)
		return (NULL);
	while (first <= last)
		ts[i++] = s[first++];
	ts[i] = 0;
	return (ts);
}

char		*ft_strtrim(char const *s)
{
	if (s != NULL)
		return (ft_strtrim_exec(s));
	return (NULL);
}
