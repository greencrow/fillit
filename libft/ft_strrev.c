/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:00:32 by laranda           #+#    #+#             */
/*   Updated: 2017/05/08 14:17:47 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (!(rev = ft_strnew(len)))
		return (NULL);
	str += len - 1;
	while (i < len)
	{
		rev[i] = *str;
		str--;
		i++;
	}
	return (rev);
}
