/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:07:41 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 17:33:02 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*ft_get_time(t_data *file, int i)
{
	char	*tmp;
	char	*time;
	int		c;

	c = 4;
	time = malloc(sizeof(char) * 13);
	time[12] = '\0';
	tmp = ctime(&(file + i)->mtime);
	while (c < 16)
	{
		time[c - 4] = tmp[c];
		c++;
	}
	return (time);
}

void	ft_print_data(t_data *file, int i)
{
	ft_putstr(file[i].rights);
	ft_putchar(' ');
	ft_putnbr(file[i].nlink);
	ft_putchar(' ');
	ft_putstr(file[i].ui);
	ft_putchar(' ');
	ft_putstr(file[i].group);
	ft_putchar(' ');
	ft_putnbr(file[i].size);
	ft_putchar(' ');
	ft_putstr(ft_get_time(file, i));
	ft_putchar(' ');
	ft_putstr(file[i].name);
	ft_putchar('\n');
}

void	ft_print_lsl(t_data *file, char *flags)
{
	int i;

	i = 0;
	ft_putstr("total ");
	ft_putnbr(ft_nblocks(file, flags));
	ft_putchar('\n');
	while (file[i].name)
	{
		if (ft_strchr(flags, 'a') != 0)
			ft_print_data(file, i);
		else if ((file[i].name)[0] != '.' && ft_strchr(flags, 'a') == 0)
			ft_print_data(file, i);
		i++;
	}
}

void	ft_print(t_data *file, char *flags)
{
	int	i;

	i = 0;
	while (file[i].name)
	{
		if (ft_strchr(flags, 'a') != 0)
		{
			ft_putstr(file[i].name);
			ft_putchar('\n');
		}
		if ((file[i].name)[0] != '.' && ft_strchr(flags, 'a') == 0)
		{
			ft_putstr(file[i].name);
			ft_putchar('\n');
			i++;
		}
		else
			i++;
	}
}

void	print(t_data *file, char *flags)
{
	if (ft_strchr(flags, 'l') != 0)
		ft_print_lsl(file, flags);
	else
		ft_print(file, flags);
}
