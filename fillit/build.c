/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:31:15 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/04 22:03:31 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//	CREATION DE T_TETRIS

//	FREE UN T_TETRIS
void	free_tetris(t_tetris *tetris)
{
	if (!tetris)
		return;
	while (tetris->prev)
		tetris = tetris->prev;
	while (tetris->next)
	{
		//ETC...
	}
}

//	CREATION DE T_MAP
char	**make_grid(int size)
{
	char	**grid;
	int		i;

	grid = (char **)ft_memalloc(sizeof(char*) * size);
	if (grid)
	{
		i = 0;
		while (i < size)
		{
			grid[i] = (char*)ft_memalloc(size + 1);
			if (!grid[i])
			{
				while (i-- > 0)
					free(grid[i]);
				free(grid);
				return (NULL);
			}
			grid[i] = ft_memset(grid[i], '.', size);
			grid[i][size] = 0;
			i++;
		}
	}
	return (grid);
}

//	FREE MAP
