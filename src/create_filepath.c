/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_filepath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:08:40 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:18:23 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*ft_create_path(char *fpath, char *filename)
{
	char	*newstr;

	newstr = ft_strnew(ft_strlen(fpath) + ft_strlen(filename) + 1);
	newstr = ft_strcat(newstr, fpath);
	if (fpath[ft_strlen(fpath) - 1] != '/')
		newstr = ft_strcat(newstr, "/");
	newstr = ft_strcat(newstr, filename);
	return (newstr);
}
