#include "ls.h"

int	ft_get_size(t_stat filestat)
{
	return (filestat.st_size);
}
