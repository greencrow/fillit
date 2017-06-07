/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 14:46:35 by laranda           #+#    #+#             */
/*   Updated: 2017/05/01 17:06:14 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*alloc;

	if (!(alloc = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(alloc, '\0', size + 1);
	return (alloc);
}
