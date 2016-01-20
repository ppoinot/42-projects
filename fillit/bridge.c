/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 11:13:38 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/19 16:21:51 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			shapecmp(t_tetris *buff, t_tetris *tetris)
{
	int		i;
	int		j;

	if (buff->s_y != tetris->s_y || buff->s_x != tetris ->s_x)
		return (0);
	i = 0;
	while (i < buff->s_y)
	{
		j = 0;
		while (j < buff->s_x)
		{
			if (buff->shape[i][j] != tetris->shape[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_tetris	*set_bridge_p(t_tetris *tetris)
{
	t_tetris	*buff;

	buff = tetris;
	while ((buff = buff->prev))
		if (shapecmp(buff, tetris))
			return (buff);
	return (NULL);
}

t_tetris	*use_bridge_p(t_tetris *tetris, int size)
{
	if (tetris && tetris->bridge_p)
	{
		tetris->c_y = tetris->bridge_p->c_y;
		tetris->c_x = tetris->bridge_p->c_x;
		ft_move_right(tetris, size);
	}
	return (tetris);
}
