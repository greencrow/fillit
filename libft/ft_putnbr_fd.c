/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laranda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:16:19 by laranda           #+#    #+#             */
/*   Updated: 2017/04/28 19:47:22 by laranda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	m;

	m = n;
	if (m < 0)
	{
		ft_putchar_fd('-', fd);
		m = -m;
	}
	if (0 <= m && m <= 9)
		ft_putchar_fd('0' + m, fd);
	else
	{
		if (m > 0)
		{
			ft_putnbr_fd(m / 10, fd);
			ft_putchar_fd('0' + (m % 10), fd);
		}
		else
		{
			ft_putnbr_fd((-m) / 10, fd);
			ft_putchar_fd('0' + ((-1) % 10), fd);
		}
	}
}
