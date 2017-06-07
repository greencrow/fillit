/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:06:22 by svigouro          #+#    #+#             */
/*   Updated: 2017/06/06 18:53:23 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		inside_board(t_tetri *tetrimino, int size)
{
	return ((tetrimino->offset / 11) + tetrimino->height <= size);
}

int		end_of_line(t_tetri *tetrimino, int size)
{
	return ((tetrimino->offset % 11) + tetrimino->width > size);
}

void	next_line(t_tetri *tetrimino)
{
	tetrimino->offset += 11 - (tetrimino->offset % 11);
}

int		possible_move(__int128 board, t_tetri *tetrimino)
{
	return ((board & (tetrimino->tetri >> tetrimino->offset)) == 0);
}

int		solve_tetri(__int128 board, t_tetri *tetriminos, int size)
{
	if (!tetriminos)
		return (1);
	while (inside_board(tetriminos, size))
	{
		if (end_of_line(tetriminos, size))
			next_line(tetriminos);
		else
		{
			if (possible_move(board, tetriminos))
			{
				if (solve_tetri((
							board | (tetriminos->tetri >> tetriminos->offset)),
							tetriminos->next, size))
					return (1);
			}
			(tetriminos->offset)++;
		}
	}
	tetriminos->offset = 0;
	return (0);
}
