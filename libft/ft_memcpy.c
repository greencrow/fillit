/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 11:55:51 by laranda           #+#    #+#             */
/*   Updated: 2017/04/27 19:09:38 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dup_dst;
	char	*dup_src;

	dup_dst = dst;
	dup_src = (void*)src;
	while (n)
	{
		*dup_dst = *dup_src;
		dup_dst++;
		dup_src++;
		n--;
	}
	return (dst);
}
