/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:39:02 by ppoinot           #+#    #+#             */
/*   Updated: 2016/12/05 18:18:25 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_swapping(char *s, int i)
{
	char	*swap;

	swap = ft_strdup(s + i + 1);
	free(s);
	return (swap);
}

t_gnl	*resolve(t_gnl **gnl, char ***line)
{
	int		nb;

	if ((*gnl)->ret)
	{
		(*gnl)->string = ft_strjoin((*gnl)->string, (*gnl)->buffer);
		free((*gnl)->buffer);
		nb = ft_count((*gnl)->string, '\n');
		if (ft_strchr((*gnl)->string, '\n'))
		{
			if (nb < (*gnl)->ret)
				(*gnl)->string = ft_swapping((*gnl)->string, nb);
		}
		**line = ft_strsub((*gnl)->string, 1, nb);
	}
	return (*gnl);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;

	if (BUFF_SIZE < 1 || !line)
		return (-1);
	if (!(gnl = (t_gnl*)malloc(sizeof(gnl)))
			|| !(gnl->string = ft_strnew(BUFF_SIZE + 1))
			|| !(gnl->buffer = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	gnl->ret = 1;
	while (gnl->ret != 0 && !ft_strchr(gnl->string, '\n'))
	{
		if ((gnl->ret = read(fd, gnl->buffer, BUFF_SIZE)) < 0)
			return (-1);
		gnl = resolve(&gnl, &line);
	}
	if (gnl->ret != 0)
		return (1);
	free(gnl);
	return (0);
}

/*int		main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
		ft_putendl(line);
		if (ft_strcmp(line, "aaa") == 0)
			ft_putendl("OK");
		else
			ft_putendl("KO");
		free(line);
	}
	close(fd);
	return (1);
}*/
