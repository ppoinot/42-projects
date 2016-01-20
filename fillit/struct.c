/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:31:15 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/19 15:56:47 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**make_grid(int size_y, int size_x)
{
	char	**grid;
	int		i;

	grid = (char **)ft_memalloc(sizeof(char*) * size_y);
	if (grid)
	{
		i = 0;
		while (i < size_y)
		{
			grid[i] = (char*)ft_memalloc(size_x + 1);
			if (!grid[i])
			{
				while (i-- > 0)
					free(grid[i]);
				free(grid);
				return (NULL);
			}
			grid[i] = ft_memset(grid[i], '.', size_x);
			grid[i][size_x] = 0;
			i++;
		}
	}
	return (grid);
}

void	free_grid(char **map, int size_y)
{
	int		i;

	i = 0;
	while (i < size_y)
		free(map[i++]);
	free(map);
}

void	ft_trim_is_life(t_tetris *tetris, char **buff)
{
	int		i;
	int		j;

	i = 0;
	tetris->c_y = tetris->c_y - tetris->s_y + 1;
	tetris->c_x = tetris->c_x - tetris->s_x + 1;
	while (i < tetris->s_y)
	{
		j = 0;
		while (j < tetris->s_x)
		{
			buff[i][j] = tetris->shape[tetris->c_y + i][tetris->c_x + j];
			j++;
		}
		i++;
	}
	tetris->bridge_p = set_bridge_p(tetris);
	tetris->c_y = 0;
	tetris->c_x = 0;
	free_grid(tetris->shape, 4);
	tetris->shape = buff;
}

int		ft_trim_tetris(t_tetris *tetris)
{
	char	**buff;
	int		i;

	i = 0;
	tetris->s_y = 4;
	tetris->s_x = 4;
	while (i < 4)
	{
		(!(ft_strcmp(tetris->shape[i], "...."))) ?
			(tetris->s_y--) : (tetris->c_y = i);
		(tetris->shape[0][i] == '.' && tetris->shape[1][i] == '.' &&
		 tetris->shape[2][i] == '.' && tetris->shape[3][i] == '.') ?
			(tetris->s_x--) : (tetris->c_x = i);
		i++;
	}
	if (!(buff = make_grid(tetris->s_y, tetris->s_x)))
		return (0);
	ft_trim_is_life(tetris, buff);
	return (1);
}

int		ft_greaterroot(int nb_tetris)
{
	int		i;

	if (nb_tetris < 1 || nb_tetris > 26)
		return (0);
	i = 2;
	while (i * i < 4 * nb_tetris)
		i++;
	return (i);
}
