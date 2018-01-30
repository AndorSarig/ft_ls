#include "ls.h"

void	ft_swap_data(data *first, data *second)
{
	data	*tmp;

	tmp = malloc(sizeof(data));
	*tmp = *first;
	*first = *second;
	*second = *tmp;
}
