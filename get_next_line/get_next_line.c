/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:16:42 by ppoinot           #+#    #+#             */
/*   Updated: 2016/03/18 16:48:45 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_realloc(size_t ol, t_gnl *c_s)
{
	char		*buff2;
	char		*buff1
	size_t		i;
	size_t		n;//	size buff (!= BUFF_SIZE)

	i = 0;
	n = ft_strlen(c_s->sentence);
	while (c_s->sentence[i] != '\n' && c_s->sentence[i])
		i++;
	if (i >= n)
		{
			if ((ol = read(c_s->fd, buff, BUFF_SIZE)) == -1)
				return (NULL);
			gnl_realloc(ol, c_s);
		}
	sentence = ft_realloc(buff, i);
	return (sentence);
}

int		get_next_line(int const fd, char **line)
{
	static t_gnl	*static_struct;
	t_gnl			*c_s;//		current_struct
	size_t			ol;//		nb_oc_lu

	c_s->fd = fd;
	if (!(c_s->sentence = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	if ((ol = read(c_s->fd, c_s->sentence, BUFF_SIZE)) != -1 ||
		(ol != 0))
	{
		c_s->sentence = gnl_realloc(ol, c_s);
	}
	else if (ol == 0)
		//EOF = 1;
	return (0);
}
