/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:48:31 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:28:59 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_bad_arg(char *path, int npaths)
{
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putendl(": No such file or directory");
	npaths++;
}

void	print_ill_opt(char ill)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(ill);
	ft_putchar('\n');
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
}
