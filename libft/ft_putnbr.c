/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:02:17 by laranda           #+#    #+#             */
/*   Updated: 2017/04/28 19:45:16 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	m;

	m = n;
	if (m < 0)
	{
		ft_putchar('-');
		m = -m;
	}
	if (0 <= m && m <= 9)
		ft_putchar('0' + m);
	else
	{
		if (m > 0)
		{
			ft_putnbr(m / 10);
			ft_putchar('0' + (m % 10));
		}
		else
		{
			ft_putnbr((-m) / 10);
			ft_putchar('0' + ((-1) % 10));
		}
	}
}