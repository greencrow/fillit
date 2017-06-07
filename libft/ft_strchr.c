/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 10:06:20 by laranda           #+#    #+#             */
/*   Updated: 2017/04/17 10:11:06 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c < 0 || 127 < c)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (char*)s;
		s++;
	}
	return (*s == (char)c ? (char*)s : NULL);
}
