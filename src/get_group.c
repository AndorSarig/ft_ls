#include "ls.h"

char	*ft_get_group(t_stat filestat)
{
	t_group	*gr;
	char	*group;

	if (!(gr = getgrgid(filestat.st_gid)))
		return (NULL);
	if (!(group = ft_strdup(gr->gr_name)))
		return (NULL);
	return (group);
}
