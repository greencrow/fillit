/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:44:05 by svigouro          #+#    #+#             */
/*   Updated: 2017/05/03 14:43:07 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetriminos	ft_get_tetriminos(char *file, int i)
{
	t_tetriminos	ret;

	while (file[i])
	{
		ret.tetri = ft_strsplit(file, '\n');
		if (file[i] == '\n' && file[i + 1] == '\n')
			return (ret);
		i++;
	}
	return (0);
}

static t_bool		ft_check_tetriminos(t_tetriminos to_check)
{
}

t_bool				ft_check_file(char *buf)
{
	int	i;

	i = 0;
	while (*buf)
	{
		if (ft_check_tetriminos(ft_get_tetriminos(buf, i)))
			i++;
		return (FALSE);
	}
	return (TRUE);
}
