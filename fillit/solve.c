/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 18:13:03 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/08 18:58:24 by vcharles         ###   ########.fr       */
/*   Updated: 2016/01/08 18:26:33 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_erase_tetris(char **map, int size, t_tetris *tetris)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] == tetris->pos)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	ft_write_tetris(char **map, t_tetris *tetris)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetris->s_y)
	{
		j = 0;
		while (j < tetris->s_x)
		{
			if (tetris->shape[i][j] == '#')
				map[tetris->c_y + i][tetris->c_x + j] = tetris->pos;
			j++;
		}
		i++;
	}
}

int		ft_try_slot(char **map, int size, t_tetris *tetris)
{
	int	i;
	int	j;

	if (tetris->c_y + tetris->s_y > size)
		return (0);
	if (tetris->c_x + tetris->s_x > size)
		return (0);
	i = 0;
	while (i < tetris->s_y)
	{
		j = 0;
		while (j < tetris->s_x)
		{
			if (tetris->shape[i][j] == '#' &&
					map[tetris->c_y + i][tetris->c_x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	ft_write_tetris(map, tetris);
	return (1);
}

char	**solve(t_tetris *save, int size)
{
	char		**map;
	int			solving;
	t_tetris	*tetris;

	solving = 1;
	while (solving)
	{
		map = make_grid(size, size);
		if (!map)
			return (NULL);
		tetris = save;
		// BACKTRACKING LOOP;
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
				// MOVE TETRIS RIGHT
				// IF CYCLE FINISHED
				tetris = tetris->prev;
				if (tetris)
					ft_erase_tetris(map, size, tetris);
				// RESUME CYCLE
			}
		}
		free_grid(map, size);
		size++;
	}
	return (map);
}
