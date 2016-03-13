/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:16:42 by vcharles          #+#    #+#             */
/*   Updated: 2016/03/13 02:38:24 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static t_gnl	*sentence;
	int				i;
	size_t			nb_oc_lu;

	if (!(sentence = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	if ((nb_oc_lu = read(int fd, void *sentence, size_t BUFF_SIZE)) != -1)
		&& (nb_oc_lu != 0)
	{
		line += 1;
	}
	return (0);
}
