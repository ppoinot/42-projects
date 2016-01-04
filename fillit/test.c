/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:35:29 by ppoinot           #+#    #+#             */
/*   Updated: 2016/01/04 17:05:36 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check_tetris_content(char *str)
{
	int		dieze;
	int		link;
	int		i;

	dieze = 0;
	link = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			dieze++;
			if (str[i + 1] == '#')
				link++;
			if (i < 16 && str[i + 5] == '#')
				link++;
		}
		i++;
	}
	printf("Dieze = %d\n", dieze);
	printf("Link = %d\n", link);
	if(dieze == 4 && link >= 3)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("argv = %s\n", argv[1]);
		if (check_tetris_content(argv[1]))
			printf("Valide\n");
		else
			printf("Invalide\n");
	}
	return (0);
}
