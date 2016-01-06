/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 18:13:03 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/04 19:33:02 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_greaterroot(int nb_tetris)
{
	int		i;

	i = 2;
	while (i * i < 4 * nb_tetris)
		i++;
	return (i);
}

void	solve(t_tetris *tetris, int nb_tetris)
{
	int		solving;
	int		root;

	root = ft_greaterroot(nb_tetris);
	solving = 1;
	while (solving)
	{
//		BUILD T_MAP(ROOT)
		solving = 0;
		tetris = NULL;
//		FREE T_MAP
		root++;
	}
}
