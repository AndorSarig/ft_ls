#include "ls.h"

int	ft_get_n_links(t_stat filestat)
{
	int nrlinks;

	nrlinks = filestat.st_nlink;
	return (nrlinks);
}
