/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:33:47 by ppoinot           #+#    #+#             */
/*   Updated: 2016/12/06 18:20:19 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_swapping(char *stce, int i)
{
	char	*swap;

	swap = ft_strdup(stce + i + 1);
	free(stce);
	return (swap);
}

char	*ft_copy(t_gnl **gnl, char *line)
{
	if (ft_strchr((*gnl)->stce, '\n'))
	{
		line = ft_strsub((*gnl)->stce, 0, ft_count((*gnl)->stce, '\n'));
		(*gnl)->stce = ft_swapping((*gnl)->stce, ft_count((*gnl)->stce, '\n'));
	}
	else
	{
		line = ft_strsub((*gnl)->stce, 0, ft_strlen((*gnl)->stce));
		ft_bzero((*gnl)->stce, ft_strlen((*gnl)->stce));
	}
	return (line);
}

char	*transf(char *str, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(str, buf);
	free(str);
	return (tmp);
}

int		initial(t_gnl **gnl)
{
	if (*gnl == NULL)
	{
		if (!(*gnl = (t_gnl*)malloc(sizeof(t_gnl))))
			return (0);
		(*gnl)->nb = 0;
		if (!((*gnl)->stce = ft_strnew(BUFF_SIZE + 1))
				|| !((*gnl)->buff = ft_strnew(BUFF_SIZE + 1)))
			return (0);
	}
	else if ((*gnl)->stce == NULL)
	{
		if (!((*gnl)->stce = ft_strnew(BUFF_SIZE + 1)))
			return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;

	if (BUFF_SIZE < 1 || !line || !initial(&gnl))
		return (-1);
	while (!(ft_strchr(gnl->stce, '\n')))
	{
		ft_bzero(gnl->buff, BUFF_SIZE + 1);
		if ((gnl->nb = read(fd, gnl->buff, BUFF_SIZE)) > 0)
			gnl->stce = transf(gnl->stce, gnl->buff);
		else
			break ;
	}
	if (gnl->nb < 0)
		return (-1);
	if (gnl->nb == 0 && gnl->stce[0] == '\0')
	{
		*line = NULL;
		ft_strdel(&(gnl->stce));
		ft_memdel((void**)gnl);
		return (0);
	}
	*line = ft_copy(&gnl, *line);
	return (1);
}
