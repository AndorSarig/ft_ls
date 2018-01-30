#include "ls.h"

data	*ft_get_data(char *path, data *file)
{
	DIR		*opened;
	struct dirent	*current;
	t_stat		filestat;
	int		i = 0;

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

int	ft_nblocks(data *file, char *flags)
{
	int	nblocks;
	int i;

	nblocks = 0;
	i = 0;
	while (file[i].name)
	{
		if (ft_strcmp(file[i].name, ".") != 0 && ft_strcmp(file[i].name, "..") != 0)
		{
			if (ft_strchr(flags, 'a') != 0)
				nblocks += file[i++].nrblocks;
			else
			{
				while ((file[i].name)[0] == '.')
					i++;
				nblocks += file[i].nrblocks;
			}
		}
		i++;
	}
	return (nblocks / 2);
}

int	ft_ls(char *path, char *flags)
{
	data	*file;

	file = malloc(sizeof(data) * 500);
	ft_get_data(path, file);
	if (ft_strchr(flags, 't') != NULL && ft_strchr(flags, 'r') != NULL)
		ft_sort_revtime(file);
	else if (ft_strchr(flags, 't') != NULL)
		ft_sort_time(file);
	else if (ft_strchr(flags, 'r') != NULL)
		ft_sort_revalph(file);
	printf("%s:\n", path);
	print(file, flags);
	return (0);
}
