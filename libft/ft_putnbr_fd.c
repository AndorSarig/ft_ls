/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:27:01 by asarig            #+#    #+#             */
/*   Updated: 2017/12/17 18:50:26 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static int	ft_div(int len)
{
	int	div;

	div = 1;
	while (len - 1)
	{
		div *= 10;
		len--;
	}
	return (div);
}

void		ft_putnbr_fd(int n, int fd)
{
	int	len;
	int	div;

	len = ft_intlen(n);
	div = ft_div(len);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n != -2147483648)
			n = -n;
	}
	if (n == -2147483648)
		ft_putstr_fd("2147483648", fd);
	else
	{
		while (n != 0)
		{
			ft_putchar_fd((n / div) + '0', fd);
			n %= div;
			div /= 10;
			len--;
		}
		while (len-- != 0)
			ft_putchar_fd('0', fd);
	}
}
