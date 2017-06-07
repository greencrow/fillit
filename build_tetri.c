/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:15:28 by laranda           #+#    #+#             */
/*   Updated: 2017/06/06 17:50:40 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

__int128	get_topmask(void)
{
	static __int128	topmask = 0;
	int				i;

	i = 0;
	if (!topmask)
	{
		while (i < 11)
		{
			topmask |= (__int128)1 << (126 - i);
			i++;
		}
	}
	return (topmask);
}

__int128	get_leftmask(void)
{
	static __int128	leftmask = 0;
	int				i;

	i = 0;
	if (!leftmask)
	{
		while (i < 121)
		{
			leftmask |= (__int128)1 << (126 - i);
			i += 11;
		}
	}
	return (leftmask);
}

__int128	tetri_topleft(__int128 tetri)
{
	while ((tetri & get_topmask()) == 0)
		tetri = tetri << 11;
	while ((tetri & get_leftmask()) == 0)
		tetri = tetri << 1;
	return (tetri);
}

__int128	build_tetri(char *tetri_str)
{
	__int128	tetri;
	int			n;

	tetri = 0;
	n = 0;
	while (*tetri_str)
	{
		if (*tetri_str == '\n')
		{
			n += 7;
			tetri_str++;
		}
		if (*tetri_str == '#')
			tetri |= (__int128)1 << (126 - n);
		n++;
		if (*tetri_str)
			tetri_str++;
	}
	return (tetri_topleft(tetri));
}
