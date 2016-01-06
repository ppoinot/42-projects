/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:47:27 by ppoinot           #+#    #+#             */
/*   Updated: 2016/01/04 22:03:37 by vcharles         ###   ########.fr       */
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
			if (i < 16 && str[i + 5] == '#')
				link++;
		}
		i++;
	}
	printf("Zelda = %d\n", zelda);
	printf("Link = %d\n", link);
	if (zelda == 4 && link >= 3)
		return (1);
	return (0);
}

int		check_tetris_format(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if ((i + 1) % 5)
		{
			if (str[i] != '\n')
				return (0);
		}
		else if (i == 20)
		{
			if (str[i] && str[i] != '\n')
				return (0);
		}
		else if (str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	return (check_tetris_content(str));
}

void	write_tetris(t_tetris *tetris, char *sample)
{
	// Ecris un tetriminos dans la structure
}

int		read_file(int fd, t_tetris *tetris)
{
	int			oct_read;
	char		*sample;
	int			nb_tetris;

	sample = ft_strnew(BUFF_SIZE);
	nb_tetris = 0;
	while ((oct_read = read(fd, sample, BUFF_SIZE)))
		if (check_tetris_format(sample))
		{
			write_tetris(tetris, sample);
			nb_tetris++;
		}
		else
		{
			nb_tetris = 0;
			// FREE T_TETRIS
			break;
		}
	free(sample);
	return (nb_tetris);
}

int		main(int argc, char **argv)
{
	int			fd;
	int			nb_tetris;
	t_tetris	*tetris;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			tetris = NULL;
			nb_tetris = read_file(fd, tetris);
			close(fd);
			if (0 < nb_tetris || nb_tetris < 27)
				solve(tetris, nb_tetris);
			return (0);
		}
	}
	ft_putendl("error");
	return (0);
}
