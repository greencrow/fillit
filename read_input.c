/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:06:22 by svigouro          #+#    #+#             */
/*   Updated: 2017/06/06 18:40:01 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_tetrimino(char *filename, t_tetri *tetriminos)
{
	int		fd;
	int		size_read;
	int		nb_tetri;
	char	buff[22];

	fd = open(filename, O_RDONLY);
	size_read = 21;
	nb_tetri = 0;
	if (fd != -1)
	{
		while (size_read == 21)
		{
			size_read = read(fd, buff, 21);
			if (size_read)
			{
				buff[21] = '\0';
				if (!valid_tetrimino(buff))
					return (-1);
				ft_tetri_addnew(tetriminos, build_tetri(buff));
				nb_tetri++;
			}
		}
		close(fd);
	}
	return (fd == -1 || size_read != 20 ? -1 : nb_tetri);
}
