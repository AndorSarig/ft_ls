#include "ls.h"

int	get_rec_nfiles(int i, int a, char *path)
{
	t_stat		filestat;
	struct dirent	*current;
	DIR		*opened;

	if (a == 1)
		i += 2;
	stat(path, &filestat);
	if (S_ISDIR(filestat.st_mode))
	{
		opened = opendir(path);
		current = readdir(opened);
		while (ft_strcmp(current->d_name, ".") == 0)
			current = readdir(opened);
		while ((current = readdir(opened)) != NULL)
		{
			if (current == NULL)
				return (0);
			stat(ft_create_path(path, current->d_name), &filestat);
			if (S_ISDIR(filestat.st_mode))
				i += 1 + get_rec_nfiles(0, a, ft_create_path(path, current->d_name));
			else
				i++;
		}
		if (i)
			return (i);
	}
	return (0);
}
