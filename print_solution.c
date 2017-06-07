/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:06:22 by svigouro          #+#    #+#             */
/*   Updated: 2017/06/06 16:46:03 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_solution_board(int board_size)
{
	char	*solution;
	int		i;

	i = 0;
	if (!(solution = (char*)malloc(sizeof(char) *
					((board_size * (board_size + 1) + 1)))))
		return (NULL);
	while (i < board_size * (board_size + 1))
	{
		if (i % (board_size + 1) == board_size)
			solution[i] = '\n';
		else
			solution[i] = '.';
		i++;
	}
	solution[i] = '\0';
	return (solution);
}

void	update_solution(char *solution, t_tetri *tetrimino, char letter)
{
	int			i;
	__int128	tetri;

	i = 0;
	tetri = 0;
	while (*solution)
	{
		tetri = tetrimino->tetri >> tetrimino->offset;
		if (tetri & ((__int128)1 << (126 - i)))
			*solution = letter;
		i++;
		solution++;
		if (*solution == '\n')
		{
			solution++;
			if (i % 11)
				i += 11 - (i % 11);
		}
	}
}

void	print_solution(t_tetri *tetriminos, int board_size)
{
	char	*solution;
	char	letter;

	letter = 'A';
	if ((solution = get_solution_board(board_size)))
	{
		while (tetriminos)
		{
			update_solution(solution, tetriminos, letter);
			letter++;
			tetriminos = tetriminos->next;
		}
		ft_putstr(solution);
	}
}
