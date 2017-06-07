/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:33:31 by laranda           #+#    #+#             */
/*   Updated: 2017/06/06 14:34:46 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt(int nb)
{
	int				racine;
	unsigned int	carre;
	unsigned int	unsigned_nb;

	racine = 0;
	carre = 0;
	if (nb > 0)
	{
		unsigned_nb = nb;
		while (carre < unsigned_nb)
		{
			racine++;
			carre = racine * racine;
		}
	}
	return (racine);
}

int			get_board_size(int nb_tetri)
{
	int		size;

	size = ft_sqrt(nb_tetri * 4);
	return (size);
}
