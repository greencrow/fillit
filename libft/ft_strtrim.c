/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:39:33 by laranda           #+#    #+#             */
/*   Updated: 2017/05/01 17:17:37 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		len;

	if (!(trim = ft_strdup(s)))
		return (NULL);
	len = ft_strlen(trim) - 1;
	while (trim[len] == ' ' || trim[len] == '\t' || trim[len] == '\n')
	{
		trim[len] = '\0';
		len--;
	}
	while (*trim == ' ' || *trim == '\t' || *trim == '\n')
		trim++;
	if (!(trim = ft_strdup(trim)))
		return (NULL);
	return (trim);
}
