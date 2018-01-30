/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:09:19 by asarig            #+#    #+#             */
/*   Updated: 2017/12/19 15:38:42 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cleanup(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		ft_memdel((void **)&lst);
		lst = temp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*temp;
	t_list	*new;

	if (!lst)
		return (NULL);
	temp = f(lst);
	new = ft_lstnew(temp->content, temp->content_size);
	if (new == NULL)
		return (NULL);
	node = new;
	while (lst->next)
	{
		lst = lst->next;
		temp = f(lst);
		node->next = ft_lstnew(temp->content, temp->content_size);
		if (node->next == NULL)
		{
			cleanup(new);
			return (NULL);
		}
		node = node->next;
	}
	return (new);
}
