/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:53:24 by laranda           #+#    #+#             */
/*   Updated: 2017/06/06 14:47:07 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_width(__int128 tetri)
{
	int	width;

	width = 0;
	while ((tetri & get_leftmask()) != 0)
	{
		tetri <<= 1;
		width++;
	}
	return (width);
}

int		get_height(__int128 tetri)
{
	int	height;

	height = 0;
	while ((tetri & get_topmask()) != 0)
	{
		tetri <<= 11;
		height++;
	}
	return (height);
}

t_tetri	*ft_tetrinew(__int128 tetri)
{
	t_tetri	*new;

	if (!(new = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	if (!(new->tetri = (__int128)malloc(16)))
		return (NULL);
	if (!(new->width = (int)malloc(sizeof(int))))
		return (NULL);
	if (!(new->height = (int)malloc(sizeof(int))))
		return (NULL);
	if (!(new->offset = (int)malloc(sizeof(int))))
		return (NULL);
	new->tetri = tetri;
	new->width = get_width(tetri);
	new->height = get_height(tetri);
	new->offset = 0;
	new->next = NULL;
	return (new);
}

void	ft_tetriadd(t_tetri *alst, t_tetri *new)
{
	if (alst->tetri)
	{
		while (alst->next)
			alst = alst->next;
		alst->next = new;
	}
	else
	{
		alst->tetri = new->tetri;
		alst->height = new->height;
		alst->width = new->width;
		alst->offset = new->offset;
	}
}

void	ft_tetri_addnew(t_tetri *alst, __int128 tetri)
{
	ft_tetriadd(alst, ft_tetrinew(tetri));
}
