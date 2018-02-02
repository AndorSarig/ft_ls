#include "ls.h"

void	ft_free_data(t_data *file)
{
	int i;

	i = 0;
	while (file[i].name)
	{
		free(file[i].name);
		free(file[i].path);
		free(file[i].rights);
		free(file[i].ui);
		free(file[i].group);
		free(file[i].mt);
		i++;
	}
}
