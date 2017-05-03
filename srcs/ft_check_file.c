/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:44:05 by svigouro          #+#    #+#             */
/*   Updated: 2017/05/02 14:42:03 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetriminos	*ft_get_tetriminos(char *file, int i)
{
	t_tetriminos	ret;
	int				*ptr;

	ptr = &i;
	while (file[*ptr])
	{
		while (file[*ptr] != '\n' && file[*ptr + 1] != '\n');
		{
			while (file[*ptr] != '\n')
				ret->line1 = file[*ptr++];
			*ptr++;
			while (file[*ptr] != '\n')
				ret->line2 = file[*ptr++];
			*ptr++;
			while (file[*ptr] != '\n')
				ret->line3 = file[*ptr++];
			*ptr++;
			while (file[*ptr] != '\n')
				ret->line4 = file[*ptr++];
			*ptr++;
		}
	}
}

static t_bool		ft_check_tetriminos(t_tetriminos to_check)
{

}

t_bool				ft_check_file(char *buf)
{
	int		i;

	i = 0;
	while (*buf)
	{
		if (ft_check_tetriminos(ft_get_tetriminos(buf, i)))
			i++;
		return (FALSE);
	}
	return (TRUE);
}
