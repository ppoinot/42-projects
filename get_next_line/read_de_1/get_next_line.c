/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:24:49 by ppoinot           #+#    #+#             */
/*   Updated: 2016/12/07 11:54:33 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		cleanthis(char **line, char **stce, char **buff, int *i)
{
	if (!(*line = ft_strdup(*stce)))
		return (-1);
	ft_strdel(&*stce);
	ft_strdel(&*buff);
	if (i[0] == 0)
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				i[2];
	char			*buff;
	static char		*stce = NULL;

	i[0] = 0;
	i[1] = 0;
	if (fd < 0 || !line || !*line || BUFF_SIZE < 1)
		return (-1);
	while (i[1] < BUFF_SIZE)
	{
		if (!stce)
			stce = ft_strnew(2);
		buff = ft_strnew(2);
		if ((i[0] = ft_read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		if (*buff != '\n' && i[0] != 0)
			stce = ft_strjoin(stce, buff);
		if (*buff == '\n' || i[0] == 0)
			return (cleanthis(line, &stce, &buff, i));
		i[1]++;
	}
	if (i[1] == BUFF_SIZE)
		return (get_next_line(fd, line));
	return (-1);
}

/*int     main(int argc, char **argv)
{
	int     fd;
	char    *line;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
		ft_putendl("LINE");
		ft_putendl(line);
		free (line);
	}
	return (1);
}*/
