/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:59:08 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 16:50:07 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nr(const char *str)
{
	int		nbr;

	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr);
}

int			ft_atoi(const char *str)
{
	int		elojel;
	int		szam;

	elojel = 1;
	while (*str == '\t' || *str == ' ' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '-')
		elojel = -1;
	if (*str == '-' || *str == '+')
		str++;
	szam = ft_nr(str) * elojel;
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	else
		return (szam);
}
