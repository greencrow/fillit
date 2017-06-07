/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 10:11:52 by laranda           #+#    #+#             */
/*   Updated: 2017/04/28 17:54:06 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (c < 0 || 127 < c)
		return (NULL);
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (char*)&s[i];
		i--;
	}
	return (s[i] == (char)c ? (char*)&s[i] : NULL);
}
