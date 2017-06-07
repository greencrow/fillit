/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:05:00 by laranda           #+#    #+#             */
/*   Updated: 2017/05/08 13:57:04 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*mapnext;

	map = f(lst);
	lst = lst->next;
	mapnext = map;
	while (lst)
	{
		mapnext->next = f(lst);
		mapnext = mapnext->next;
		lst = lst->next;
	}
	return (map);
}
