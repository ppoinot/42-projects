/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:32:31 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/14 16:38:21 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_erase_tetris(char **map, t_tetris *tetris)
{
	int i;
	int j;

	i = 0;
	while (i < tetris->s_y)
	{
		j = 0;
		while (j < tetris->s_x)
		{
			if (map[tetris->c_y + i][tetris->c_x + j] == tetris->pos)
				map[tetris->c_y + i][tetris->c_x + j] = '.';
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

char	**solve(t_tetris *tetris, int size)
{
	char		**map;
	int			solving;

	solving = 1;
	while (solving)
	{
		map = make_grid(size, size);
		if (!map)
			return (NULL);
		map = backtracking(tetris, map, size);
		if (map[0][0] == '.')
		{
			free_grid(map, size);
			size++;
		}
		else
			solving = 0;
	}
	return (map);
}
