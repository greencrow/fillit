/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:14:31 by laranda           #+#    #+#             */
/*   Updated: 2017/05/23 20:34:39 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_char(char c)
{
	if (c != '.' && c != '#' && c != '\n')
		return (0);
	return (1);
}

int		valid_format(char *tetrimino)
{
	int		newline;
	int		line_length;

	newline = 0;
	line_length = 0;
	if (ft_strlen(tetrimino) < 20)
		return (0);
	while (*tetrimino)
	{
		if (!valid_char(*tetrimino))
			return (0);
		if (*tetrimino == '\n')
		{
			newline++;
			if (line_length != 4 && newline != 5)
				return (0);
			line_length = -1;
		}
		line_length++;
		tetrimino++;
	}
	return (newline == 4 || newline == 5 ? 1 : 0);
}

int		nb_connections(t_coord *sq)
{
	int		connections;
	int		i;
	int		j;

	connections = 0;
	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if ((sq[i].x == sq[j].x && ABS(sq[i].y - sq[j].y) == 1)
					|| (sq[i].y == sq[j].y && ABS(sq[i].x - sq[j].x) == 1))
				connections++;
			j++;
		}
		i++;
	}
	return (connections);
}

int		valid_tetrimino(char *tetrimino)
{
	t_coord	squares[4];
	int		square;
	int		i;

	square = 0;
	i = 0;
	if (!valid_format(tetrimino))
		return (0);
	while (tetrimino[i])
	{
		if (tetrimino[i] == '#')
		{
			squares[square].x = i % 5;
			squares[square].y = i / 5;
			square++;
		}
		i++;
	}
	if (square != 4)
		return (0);
	return (nb_connections(squares) > 2 ? 1 : 0);
}
