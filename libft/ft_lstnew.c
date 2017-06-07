/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 15:12:04 by laranda           #+#    #+#             */
/*   Updated: 2017/05/08 13:40:36 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = (void*)malloc(content_size + 1)))
		return (NULL);
	if (!content)
		new->content = NULL;
	else
		ft_memcpy(new->content, content, content_size);
	new->content_size = content == NULL ? 0 : content_size;
	new->next = NULL;
	return (new);
}
