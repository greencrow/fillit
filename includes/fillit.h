/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:26:07 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/28 15:41:18 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define TRUE 1
# define FALSE 0

typedef struct	s_tetriminos
{
	size_t	length;
	size_t	height;
	char	*line1;
	char	*line2;
	char	*line3;
	char	*line4;
}				t_tetriminos;

typedef int		t_bool;

#endif
