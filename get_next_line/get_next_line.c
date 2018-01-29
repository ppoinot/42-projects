/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 12:30:42 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/04 11:08:25 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_return(char **line, char **stce)
{
	size_t		len;
	char		*tmp;

	len = ft_strchr(*stce, '\n') - *stce;
	tmp = *stce;
	*line = ft_strsub(tmp, 0, len);
	*stce = ft_strdup(tmp + len + 1);
	if ((*stce)[0] == '\0')
		ft_strdel(stce);
	free(tmp);
}

static int		ft_end_of_file(char **line, char **stce)
{
	if (!(*stce)[0])
	{
		ft_strdel(stce);
		return (0);
	}
	*line = ft_strdup(*stce);
	ft_strdel(stce);
	return (1);
}

static int		ft_error(char **stce)
{
	if (*stce)
		ft_strdel(stce);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	static char	*stce = NULL;
	char		*tmp;

	ret = 0;
	if (fd == -1 || BUFF_SIZE <= 0)
		return (ft_error(&stce));
	if (stce == NULL)
		stce = ft_strnew(BUFF_SIZE + 1);
	while (stce != NULL
			&& ft_strchr(stce, '\n') == NULL
			&& ((ret = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[ret] = '\0';
		tmp = stce;
		stce = ft_strjoin(tmp, buff);
		free(tmp);
	}
	if (ret == -1 || stce == NULL)
		return (-1);
	if (ret == 0 && ft_strchr(stce, '\n') == NULL)
		return (ft_end_of_file(line, &stce));
	ft_return(line, &(stce));
	return (1);
}
