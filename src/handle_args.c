/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:57:45 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:30:29 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ft_count_paths(char **argv)
{
	int	i;
	int paths;

	i = 0;
	paths = 0;
	while (argv[i])
	{
		if (argv[i][0] != '-')
			paths++;
		i++;
	}
	return (paths);
}

void	handle_args2(char **argv, char *flags, t_stat path, int i)
{
	if (ft_count_paths(argv) > 1 && i != 1)
		ft_putstr(ft_strjoin(argv[i], ":\n"));
	recursive(ft_create_path(".", argv[i]), flags, 0);
}

int		ft_handle_args(char **argv)
{
	char	*flags;
	int		i;
	int		npaths;
	t_stat	path;

	i = 0;
	npaths = 0;
	if ((flags = ft_get_flags(argv)) == NULL)
		return (-1);
	while (argv[++i] != NULL)
	{
		if (argv[i][0] != '-')
		{
			stat(argv[i], &path);
			if (S_ISDIR(path.st_mode))
				handle_args2(argv, flags, path, npaths++);
			else
				print_bad_arg(argv[i], i);
		}
	}
	if (npaths == 0)
		recursive(".", flags, 0);
	return (0);
}
