/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:49:13 by laranda           #+#    #+#             */
/*   Updated: 2017/04/27 14:52:08 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static int	wordl(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static char	*next_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_strnew(wordl(s, c));
	while (*s && *s != c)
	{
		word[i] = *s;
		s++;
		i++;
	}
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;

	i = 0;
	if (!(split = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(split[i] = (char*)malloc(sizeof(char) * (wordl(s, c) + 1))))
				return (NULL);
			ft_strcpy(split[i], next_word(s, c));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	split[i] = 0;
	return (split);
}
