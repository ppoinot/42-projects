/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:16:42 by ppoinot           #+#    #+#             */
/*   Updated: 2016/03/24 18:42:44 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_lecture(t_gnl *c_s, int fd, size_t ol)
{
	int		x;
	int		i;
	char	*buff_1;

	x = 0;
	i = 0;
	if (!(buff_1 = (char*)malloc(sizeof(char) * BUFF_SIZE)) ||
		(ol = read(fd, buff_1, BUFF_SIZE)) != -1)
		return (-1);
	if (ol == 0)
		return (-2); //EOF = 1
	while (buff_1[i])
	{
		if (buff_1[i] == '\n')
		{
			x = i;
			break;
		}
		i++;
	}
	return (x);
}

char	*gnl_realloc(t_gnl *c_s, int x, char *buff_1)
{
	if (x == 0)
	{
		buff_1 = ft_realloc(buff_1, ft_strlen + BUFF_SIZE);
	}
	buff_1 = ft_realloc(buff_1, x);
	ft_putstr(buff_1);
	return (buff_1);
}

int		get_next_line(int const fd, char **line)
{
	static t_gnl	*static_struct;
	t_gnl			*c_s;//		current_struct
	size_t			ol;//		nb_oc_lu

	c_s->fd = fd;
	if (!(c_s->sentence = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);

	return (0);
}
