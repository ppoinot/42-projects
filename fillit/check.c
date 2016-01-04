/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:47:27 by ppoinot           #+#    #+#             */
/*   Updated: 2016/01/04 15:20:45 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 16384

#include "libft.h"

static char		*add_tetris(int fd)
{
    int			oct_read;
	char		*sample;

	oct_read = read(fd, sample, BUF_SIZE);
	if (oct_read == -1)
		return (NULL);
}

int		main(void)
{
	int		fd;
void
	fd = -1;
	fd = open("sample.fillit", O_RDONLY);
	if (fd != -1)
	{
		char* = add_tetris(fd);
		if (close(fd) == -1)
		{
			ft_putstr("close() error");
			return (0);
		}
		return(1);
	}
	return (0);
}
