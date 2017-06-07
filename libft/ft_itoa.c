/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 20:30:15 by laranda           #+#    #+#             */
/*   Updated: 2017/05/01 20:32:14 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	concat_str(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
}

static void	concat_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	str[i + 1] = '\0';
}

char		*ft_itoa(int n)
{
	char			*result;
	unsigned int	nbr_abs;

	if (!(result = (char*)malloc(sizeof(char) * 11)))
		return (0);
	*result = '\0';
	if (n < 0)
	{
		nbr_abs = -n;
		concat_char(result, '-');
	}
	else
		nbr_abs = n;
	if (nbr_abs < 10)
	{
		concat_char(result, nbr_abs + '0');
		return (result);
	}
	else
	{
		concat_str(result, ft_itoa(nbr_abs / 10));
		concat_char(result, (nbr_abs % 10) + '0');
	}
	return (result);
}
