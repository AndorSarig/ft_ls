/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:59:08 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 15:11:05 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, int c)
{
	int nr;
	int is_subs;

	nr = 0;
	is_subs = 0;
	while (*s != '\0')
	{
		if (is_subs == 1 && *s == c)
			is_subs = 0;
		if (is_subs == 0 && *s != c)
		{
			is_subs = 1;
			nr++;
		}
		s++;
	}
	return (nr);
}

static int	word_len(const char *s, int c)
{
	int len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		n_w;
	int		i;

	if (!s || !c)
		return (NULL);
	i = 0;
	n_w = count_words(s, c);
	if (!(array = (char **)ft_memalloc(sizeof(*array) * (n_w + 1))))
		return (NULL);
	while (n_w--)
	{
		while (*s == c && *s != '\0')
			s++;
		array[i] = ft_strsub(s, 0, word_len(s, c));
		if (array[i] == NULL)
			return (NULL);
		s = s + word_len(s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
