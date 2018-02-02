/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:19:23 by asarig            #+#    #+#             */
/*   Updated: 2017/12/17 17:39:53 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen1(int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static int	ft_div(int len)
{
	int div;

	div = 1;
	while (len - 1)
	{
		div *= 10;
		len--;
	}
	return (div);
}

void		ft_putnbr(int n)
{
	int div;
	int len;

	len = ft_intlen1(n);
	div = ft_div(len);
	if (n < 0)
	{
		ft_putchar('-');
		if (n != -2147483648)
			n = -n;
	}
	if (n == -2147483648)
		ft_putstr("2147483648");
	else
	{
		while (len)
		{
			ft_putchar((n / div) + '0');
			n %= div;
			div /= 10;
			len--;
		}
		while (len-- != 0)
			ft_putchar('0');
	}
}
