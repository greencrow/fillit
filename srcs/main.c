/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:22:43 by svigouro          #+#    #+#             */
/*   Updated: 2017/05/02 14:43:11 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

int		main(int argc, const char *argv[])
{
	int		fd;
	char	*buf;

	(void)argv;
	if (argc != 2)
	{
		ft_putendl_fd("usage:\t./fillit map_file", 1);
		return (-1);
	}
	if((fd = open(argv[1], O_RDONLY) == -1))
	{
		ft_putendl_fd("Err:\topen() failed", 1);
		return (-1);
	}
	read(fd, buf, BUF_SIZE);
	if (!(ft_check_file(buf)))
	{
		ft_putendl_fd("error");
		return (-1);
	}
	if (close(fd) == -1)
	{
		ft_putendl_fd("Err:\tclose() failed", 1);
		return (-1);
	}
	return (0);
}
