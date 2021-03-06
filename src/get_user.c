/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:25:53 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:25:54 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*ft_get_user(t_stat filestat)
{
t_passwd	*pw;
char		*name;

	if (!(pw = getpwuid(filestat.st_uid)))
		return (NULL);
	if (!(name = ft_strdup(pw->pw_name)))
		return (NULL);
	return (name);
}
