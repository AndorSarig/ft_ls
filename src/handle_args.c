#include "ls.h"

int	ft_handle_args(char **argv)
{
	char *flags;
	int i = 1;
	int	npaths = 0;
	t_stat	path;

	if ((flags = ft_get_flags(argv)) == NULL)
		return (-1);
	while (argv[i] != NULL)
	{
		if (argv[i][0] != '-')
		{
			stat(argv[i], &path);
			if (S_ISDIR(path.st_mode))
			{
				recursive(ft_create_path(".", argv[i]), flags);
				npaths++;
			}
			else
				printf("INVALID PATH\n");
		}
		i++;
	}
	if (npaths == 0)
		recursive(".", flags);
	return (npaths);
}
