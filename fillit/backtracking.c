/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:12:06 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/18 13:38:09 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_move_right(t_tetris *tetris, int size)
{
	tetris->c_x++;
	if (tetris->c_x >= size)
	{
		tetris->c_y++;
		tetris->c_x = 0;
	}
}

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

char	**backtracking(t_tetris *tetris, char **map, int size)
{
	while (tetris)
	{
		if (ft_try_slot(map, size, tetris))
			tetris = tetris->next;
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
				{
					free_grid(map, size);
					return (NULL);
				}
			}
		}
	}
	return (map);
}
