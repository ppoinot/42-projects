/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:16:42 by ppoinot           #+#    #+#             */
/*   Updated: 2016/03/15 00:00:58 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_realloc(char *buff)
{
	char	*sentence;
	size_t		i;
	size_t		n;


	return (sentence);
}

int		get_next_line(int const fd, char **line)
{
	static t_gnl	*static_struct;
	t_gnl			*current_struct;
	int				i;
	size_t			nb_oc_lu;

	if (!(current_struct->sentence = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	if ((nb_oc_lu = read(fd, current_struct->sentence, BUFF_SIZE)) != -1 ||
		(nb_oc_lu != 0))
	{
		current_struct->fd = fd;
		current_struct->line += 1;
		
	}
	return (0);
}
