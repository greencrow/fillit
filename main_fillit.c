/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:36:16 by laranda           #+#    #+#             */
/*   Updated: 2017/06/06 17:24:38 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetri		*tetriminos;
	int			nb_tetriminos;
	__int128	board;
	int			size;

	tetriminos = ft_tetrinew(0);
	nb_tetriminos = -1;
	board = 0;
	size = 0;
	if (argc == 2)
	{
		nb_tetriminos = read_tetrimino(argv[1], tetriminos);
		if (nb_tetriminos > 0)
		{
			size = get_board_size(nb_tetriminos);
			while ((!solve_tetri(board, tetriminos, size)) && size <= 11)
				size++;
			print_solution(tetriminos, size);
		}
		else
			ft_putstr("error\n");
	}
	return (0);
}
