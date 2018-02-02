/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:37:26 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:25:15 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
