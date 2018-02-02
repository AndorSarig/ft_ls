/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:37:43 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:26:03 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int	ft_get_n_links(t_stat filestat)
{
	int nrlinks;

	nrlinks = filestat.st_nlink;
	return (nrlinks);
}
