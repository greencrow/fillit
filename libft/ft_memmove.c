/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 13:25:46 by laranda           #+#    #+#             */
/*   Updated: 2017/04/30 19:29:35 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	char	*dup_dst;
	char	*dup_src;

	dup_dst = &(dst[n - 1]);
	dup_src = (void*)&(src[n - 1]);
	while (n)
	{
		*dup_dst = *dup_src;
		dup_dst--;
		dup_src--;
		n--;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (src < dst)
		ft_memrcpy(dst, src, len);
	return (dst);
}
