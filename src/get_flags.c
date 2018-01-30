#include "ls.h"

int	check_ill_option(char **argv, int n)
{
	int i = 1;

	while (argv[n][i])
	{
		if (argv[n][i] != 'R' && argv[n][i] != 't' && argv[n][i] != 'r'
			&& argv[n][i] != 'a' && argv[n][i] != 'l')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_flags(char **argv)
{
	int i = 1;
	char *flags;

	if (!(flags = malloc(sizeof(char) * 6)))
		return NULL;
	flags[5] = '\0';
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '-')
		{
			if (check_ill_option(argv, i) == 1)
				return (NULL);
			if (ft_strchr(argv[i], 'R') != NULL)
				flags[0] = 'R';
			else if (flags[0] == '\0' || flags[0] == ' ')
				flags[0] = ' ';
			if (ft_strchr(argv[i], 't') != NULL)
				flags[1] = 't';
			else if (flags[1] == '\0' || flags[1] == ' ')
				flags[1] = ' ';
			if (ft_strchr(argv[i], 'r') != NULL)
				flags[2] = 'r';
			else if (flags[2] == '\0' || flags[2] == ' ')
				flags[2] = ' ';
			if (ft_strchr(argv[i], 'a') != NULL)
				flags[3] = 'a';
			else if (flags[3] == '\0' || flags[3] == ' ')
				flags[3] = ' ';
			if (ft_strchr(argv[i], 'l') != NULL)
				flags[4] = 'l';
			else if (flags[4] == '\0' || flags[4] == ' ')
				flags[4] = ' ';
		}
		i++;
	}
	return (flags);
}
