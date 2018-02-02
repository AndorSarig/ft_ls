/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:13:14 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:27:25 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	recursive2(char *path, char *flags, int a)
{
	if (ft_strchr(flags, 'a') == NULL && ft_strstr(path, "/.") == NULL)
	{
		if (a == 1)
		{
			ft_putchar('\n');
			ft_putstr(ft_strjoin(path, ":\n"));
		}
		ft_ls(path, flags);
	}
	else if (ft_strchr(flags, 'a') != NULL)
	{
		if (a == 1)
		{
			ft_putchar('\n');
			ft_putstr(ft_strjoin(path, ":\n"));
		}
		ft_ls(path, flags);
	}
}

int		recursive(char *path, char *flags, int a)
{
	DIR				*opened;
	struct dirent	*current;
	t_stat			filestat;

	opened = opendir(path);
	if (ft_strchr(flags, 'R'))
	{
		while ((current = readdir(opened)))
		{
			stat(current->d_name, &filestat);
			if (S_ISDIR(filestat.st_mode))
				if (ft_strcmp(current->d_name, ".") == 0)
					recursive2(path, flags, a);
			if (ft_strcmp(current->d_name, ".") != 0 && ft_strcmp(current->d_name, "..") != 0)
			{
				stat(ft_create_path(path, current->d_name), &filestat);
				if (S_ISDIR(filestat.st_mode))
					recursive(ft_create_path(path, current->d_name), flags, 1);
			}
		}
	}
	else
		ft_ls(path, flags);
	return (0);
}
