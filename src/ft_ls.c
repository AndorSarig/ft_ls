/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:32:42 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 17:42:20 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_data	*ft_get_data(char *path, t_data *file)
{
	DIR				*opened;
	struct dirent	*current;
	t_stat			filestat;
	int				i;

	i = 0;
	stat(path, &filestat);
	if (S_ISDIR(filestat.st_mode))
	{
		opened = opendir(path);
		while ((current = readdir(opened)))
		{
			stat(ft_create_path(path, current->d_name), &filestat);
			(file + i)->path = ft_strdup(path);
			(file + i)->name = ft_strdup(current->d_name);
			ft_get_data_of_file(path, filestat, (file + i));
			i++;
		}
	}
	return (file);
}

int		ft_nblocks(t_data *file, char *flags)
{
	int	nblocks;
	int	i;

	nblocks = 0;
	i = 0;
	while (file[i].name)
	{
		if (ft_strcmp(file[i].name, ".") != 0 &&
				ft_strcmp(file[i].name, "..") != 0)
		{
			if (ft_strchr(flags, 'a') != 0)
				nblocks += file[i].nrblocks;
			else
			{
				if (file[i].nrblocks && (file[i].name)[0] != '.')
					nblocks += file[i].nrblocks;
			}
		}
		i++;
	}
	return (nblocks);
}

int		ft_get_nrfiles(char *path)
{
	DIR				*opened;
	struct dirent	*current;
	int				i;

	i = 0;
	opened = opendir(path);
	while ((current = readdir(opened)))
		i++;
	return (i);
}

int		ft_ls(char *path, char *flags)
{
	t_data	*file;
	int		nrfiles;

	nrfiles = ft_get_nrfiles(path);
	file = (t_data *)malloc(sizeof(t_data) * nrfiles);
	ft_get_data(path, file);
	ft_sort_abc(file);
	if (ft_strchr(flags, 't') != NULL && ft_strchr(flags, 'r') != NULL)
		ft_sort_revtime(file);
	else if (ft_strchr(flags, 't') != NULL)
		ft_sort_time(file);
	else if (ft_strchr(flags, 'r') != NULL)
		ft_sort_revalph(file);
	print(file, flags);
	ft_free_data(file);
	return (0);
}
