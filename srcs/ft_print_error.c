/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:18:45 by svigouro          #+#    #+#             */
/*   Updated: 2017/05/03 14:22:28 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_error(int type)
{
	if (type == 0)
		return ;
	if (type == 1)
		ft_putendl("usage:\t./fillit map_file");
	if (type == 2)
		ft_putendl("error");
}
