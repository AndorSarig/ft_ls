#include "ls.h"

char	*ft_mod_time(t_stat filestat)
{
	char	*time;
	char	*tmp;
	int	i;

	i = 0;
	tmp = ctime(&filestat.st_mtime);
	time = malloc(sizeof(char) * 13);
	time[12] = '\0';
	while (i < 12)
	{
		time[i] = tmp[i + 4];
		i++;
	}
	return (time);
}

void	ft_get_data_of_file(char *filepath, t_stat filestat, data *current)
{
	current->rights = ft_rights(filepath, filestat);
	current->nlink = ft_get_n_links(filestat);
	current->ui = ft_get_user(filestat);
	current->group = ft_get_group(filestat);
	current->size = ft_get_size(filestat);
	current->mtime = filestat.st_mtime;
	current->mt = ft_mod_time(filestat);
	current->nrblocks = (int)filestat.st_blocks;
}

/*
Itt current->nlink, mert pointeren beluli reszre mutat,
a masik fajlban viszont (*current).nlink.
*/
