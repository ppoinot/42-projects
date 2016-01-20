/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:32:31 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/19 15:27:32 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	cleanup(t_tetris **tetris)
{
	t_tetris	*buff;

	if (*tetris)
	{
		while ((*tetris)->prev)
			*tetris = (*tetris)->prev;
		while (*tetris)
		{
			buff = (*tetris)->next;
			free_grid((*tetris)->shape, (*tetris)->s_y);
			free(*tetris);
			*tetris = buff;
		}
	}
	free(tetris);
}

void	print_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
		ft_putendl(map[i++]);
}

void	solve(t_tetris **tetris, int size)
{
	char		**map;
	int			solving;

	solving = 1;
	while (solving)
	{
		map = make_grid(size, size);
		if (!map)
			return ;
		while ((*tetris)->prev)
			*tetris = (*tetris)->prev;
		map = backtracking(*tetris, map, size);
		if (map)
			solving = 0;
		else
			size++;
	}
	print_map(map, size);
	free_grid(map, size);
	cleanup(tetris);
}
