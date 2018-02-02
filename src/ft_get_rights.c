/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:27:15 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:18:49 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_rights2(t_stat fs, char *r)
{
	if (fs.st_mode & S_IRGRP)
		r[4] = 'r';
	else
		r[4] = '-';
	if (fs.st_mode & S_IWGRP)
		r[5] = 'w';
	else
		r[5] = '-';
	if (fs.st_mode & S_IXGRP)
		r[6] = 'x';
	else
		r[6] = '-';
	if (fs.st_mode & S_IROTH)
		r[7] = 'r';
	else
		r[7] = '-';
	if (fs.st_mode & S_IWOTH)
		r[8] = 'w';
	else
		r[8] = '-';
	if (fs.st_mode & S_IXOTH)
		r[9] = 'x';
	else
		r[9] = '-';
}

char	*ft_rights(char *filepath, t_stat fs)
{
	t_stat	linkstat;
	char	*r;

	r = ft_strnew(11);
	lstat(filepath, &linkstat);
	if (S_ISLNK(linkstat.st_mode))
		r[0] = 'l';
	else if (S_ISDIR(fs.st_mode))
		r[0] = 'd';
	else
		r[0] = '-';
	if (fs.st_mode & S_IRUSR)
		r[1] = 'r';
	else
		r[1] = '-';
	if (fs.st_mode & S_IWUSR)
		r[2] = 'w';
	else
		r[2] = '-';
	if (fs.st_mode & S_IXUSR)
		r[3] = 'x';
	else
		r[3] = '-';
	ft_rights2(fs, r);
	return (r);
}
