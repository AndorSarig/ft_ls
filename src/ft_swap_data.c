/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:28:43 by asarig            #+#    #+#             */
/*   Updated: 2018/02/02 16:19:55 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_swap_data(t_data *first, t_data *second)
{
	t_data	*tmp;

	tmp = malloc(sizeof(t_data));
	*tmp = *first;
	*first = *second;
	*second = *tmp;
}
