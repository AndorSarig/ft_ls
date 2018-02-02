/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:07:45 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:28:39 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ft_filename_cmp(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] == '.')
		i++;
	while (s2[j] == '.')
		j++;
	while (s1[i] == s2[j] || (s1[i] - 32) == s2[j] || s1[i] == (s2[j] - 32))
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
		j++;
	}
	if (s1[i] >= 65 && s1[i] <= 90 && s2[j] >= 97 && s2[j] <= 122)
		return ((s1[i] + 32) - s2[j]);
	else if (s1[i] >= 97 && s1[j] <= 122 && s2[j] >= 65 && s2[j] <= 90)
		return (s1[i] - (s2[j] + 32));
	else
		return (s1[i] - s2[j]);
}

void	ft_sort_revalph(t_data *file)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file[i].name)
	{
		while (file[j].name)
		{
			if (ft_strcmp(file[i].name, file[j].name) > 0)
				ft_swap_data((file + i), (file + j));
			else
				j++;
		}
		j = 0;
		i++;
	}
}

void	ft_sort_abc(t_data *file)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file[i].name)
	{
		while (file[j].name)
		{
			if (ft_strcmp(file[i].name, file[j].name) < 0)
				ft_swap_data((file + i), (file + j));
			else
				j++;
		}
		j = 0;
		i++;
	}
}

void	ft_sort_time(t_data *file)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file[i].mtime)
	{
		while (file[j].mtime)
		{
			if (file[i].mtime > file[j].mtime)
				ft_swap_data((file + i), (file + j));
			else
				j++;
		}
		j = 0;
		i++;
	}
}

void	ft_sort_revtime(t_data *file)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file[i].mtime)
	{
		while (file[j].mtime)
		{
			if (file[i].mtime < file[j].mtime)
				ft_swap_data((file + i), (file + j));
			else
				j++;
		}
		j = 0;
		i++;
	}
}
