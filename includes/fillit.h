/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:26:07 by svigouro          #+#    #+#             */
/*   Updated: 2017/05/03 11:39:00 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define TRUE 1
# define FALSE 0
# define BUF_SIZE 4096


typedef struct	s_tetriminos
{
	char	**tetri;
	char	x;
	char	y;
}				t_tetriminos;

typedef int		t_bool;
typedef char	*t_square;

t_bool			ft_check_file(char *buf);

#endif
