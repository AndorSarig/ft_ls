#include "ls.h"

int	recursive(char *path, char *flags)
{
	DIR	*opened;
	struct dirent	*current;
	t_stat	filestat;

	opened = opendir(path);
	if (ft_strchr(flags, 'R'))
	{
		while ((current = readdir(opened)))
		{
			stat(current->d_name, &filestat);
			if (S_ISDIR(filestat.st_mode))
			{
					if (ft_strcmp(current->d_name, ".") == 0)
					{
						if (ft_strchr(flags, 'a') == NULL && ft_strstr(path, "/.") == NULL)
						{
							ft_putchar('\n');
							ft_putstr(ft_strjoin(path, ":\n"));
							ft_ls(path, flags);
						}
						else if (ft_strchr(flags, 'a') != NULL)
						{
							ft_putchar('\n');
							ft_putstr(ft_strjoin(path, ":\n"));
							ft_ls(path, flags);
						}
					}
			}
			if (ft_strcmp(current->d_name, ".") != 0 && ft_strcmp(current->d_name, "..") != 0)
			{
				stat(ft_create_path(path, current->d_name), &filestat);
				if (S_ISDIR(filestat.st_mode))
					recursive(ft_create_path(path, current->d_name), flags);
			}
		}
	}
	else
		ft_ls(path, flags);
	return (0);
}
