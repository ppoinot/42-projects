/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:24:49 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/19 12:23:11 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		cleanthis(char **line, char **stce, char **buff, int *i)
{
	if (!(*line = ft_strdup(*stce)))
		return (-1);
	ft_strdel(&*stce);
	ft_strdel(&*buff);
	if (i[0] == 0 || i[0] == EOF)
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
	if (fd < 0 || !line || BUFF_SIZE < 1 || !*line)
		return (-1);
	while (i[1] < BUFF_SIZE)
	{
		if (!stce)
			stce = ft_strnew(2);
		buff = ft_strnew(2);
		if ((i[0] = read(fd, buff, 1)) < 0)
			return (-1);
		if (*buff != '\n' && (i[0] != 0 || i[0] != EOF))
			stce = ft_strjoin(stce, buff);
		if (*buff == '\n' || i[0] == 0 || i[0] == EOF)
			return (cleanthis(line, &stce, &buff, i));
		i[1]++;
	}
	if (i [1] == BUFF_SIZE)
		return (get_next_line(fd, line));
	return (-1);
}
