/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:02:48 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/18 20:11:56 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetris_content(char *str)
{
	int		zelda;
	int		link;
	int		i;

	zelda = 0;
	link = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			zelda++;
			if (str[i + 1] == '#')
				link++;
			if (i < 15 && str[i + 5] == '#')
				link++;
		}
		i++;
	}
	if (zelda == 4 && link >= 3)
		return (1);
	return (0);
}

int		check_tetris_format(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((i + 1) % 5 && (str[i] != '.' && str[i] != '#'))
			return (0);
		if (!((i + 1) % 5) && str[i] != '\n')
			return (0);
		i++;
	}
	return (check_tetris_content(str));
}
