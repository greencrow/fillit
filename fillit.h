/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:01:48 by laranda           #+#    #+#             */
/*   Updated: 2017/06/06 14:39:04 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define ABS(x) (x < 0 ? -(x) : x)

# include "libft/libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct	s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef	struct	s_tetri
{
	__int128		tetri;
	int				width;
	int				height;
	int				offset;
	struct s_tetri	*next;
}				t_tetri;

int				valid_tetrimino(char *tetrimino);
int				read_tetrimino(char *filename, t_tetri *tetriminos);
int				ft_sqrt(int nb);
int				get_board_size(int nb_tetri);
__int128		build_board(int size);
__int128		build_tetri(char *tetri_str);
void			ft_tetri_addnew(t_tetri *alst, __int128 tetri);
t_tetri			*ft_tetrinew(__int128 tetri);
int				solve_tetri(__int128 board, t_tetri *tetriminos, int size);
__int128		get_leftmask(void);
__int128		get_topmask(void);
void			print_solution(t_tetri *tetriminos, int board_size);
int				line_full(__int128 board, int offset, int size);

#endif
