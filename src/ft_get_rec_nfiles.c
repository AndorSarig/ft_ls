/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rec_nfiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:09:22 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:18:36 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int	get_rec_nfiles(int i, int a, char *path)
{
	t_stat			filestat;
	struct dirent	*current;
	DIR				*opened;

	stat(path, &filestat);
	if (S_ISDIR(filestat.st_mode))
	{
		opened = opendir(path);
		current = readdir(opened);
		while ((current = readdir(opened)) != NULL)
		{
			if (current == NULL)
				return (0);
			stat(ft_create_path(path, current->d_name), &filestat);
			if (S_ISDIR(filestat.st_mode))
				i += 1 + get_rec_nfiles(0, a, ft_create_path(path,
							current->d_name));
			else
				i++;
		}
		if (i)
			return (i);
	}
	return (0);
}
