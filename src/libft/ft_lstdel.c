/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:08:13 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 14:35:23 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *temp;

	if (*alst == NULL)
		return ;
	lst = *alst;
	while (lst)
	{
		temp = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = temp;
	}
	*alst = NULL;
}
