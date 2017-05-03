/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:22:43 by svigouro          #+#    #+#             */
/*   Updated: 2017/05/03 14:39:42 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

int		main(int argc, const char *argv[])
{
	int		fd;
	char	*buf;
	int		error;

	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	error = 0;
	(void)argv;
	error = (argc != 2) ? 1 : 0;
	fd = open(argv[1], O_RDONLY);
	error = (fd == 0) ? 0 : 2; 
	if (error == 0)
		read(fd, buf, BUF_SIZE);
	//error = (ft_check_file(buf)) ? 0 : 3;
	ft_print_error(error);
	if (error != 0)
		return (-1);
	return (0);
}
