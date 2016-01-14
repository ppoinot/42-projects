/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:12:06 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/14 16:42:36 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_move_right(t_tetris *tetris, int size)
{
	if (++tetris->c_x >= size)
	{
		tetris->c_y++;
		tetris->c_x = 0;
	}
}

char	**backtracking(t_tetris *tetris, char **map, int size)
{
	while (tetris)
	{
		if (ft_try_slot(map, size, tetris))
		{
			tetris = tetris->next;
			if (!tetris)
				return (map);
		}
		else
		{
			ft_move_right(tetris, size);
			while (tetris->c_y >= size)
			{
				tetris = tetris->prev;
				if (tetris)
				{
					ft_erase_tetris(map, tetris);
					ft_move_right(tetris, size);
				}
				else
					return (map);
			}
		}
	}
	return (NULL);
}
