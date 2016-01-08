/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:47:27 by ppoinot           #+#    #+#             */
/*   Updated: 2016/01/08 18:59:15 by vcharles         ###   ########.fr       */
/*   Updated: 2016/01/08 18:33:08 by ppoinot          ###   ########.fr       */
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
	if (zelda == 4 && link >= 3)
		return (1);
	return (0);
}

int		check_tetris_format(char *str)
{
	int		i;

	i = 0;
	while (str[i])
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

int		make_tetris(t_tetris *tetris, char *sample)
{
	int		i;
	int		j;

	if (!(tetris->shape = (char**)ft_memalloc(sizeof(char*) * 4)))
		return (-1);
	i = 0;
	while (i < 4)
	{
		if (!(tetris->shape[i] = (char*)ft_memalloc(5)))
		{
			free_grid(tetris->shape, i);
			return (-1);
		}
		j = 0;
		while (j < 4)
		{
			tetris->shape[i][j] = sample[5 * i + j];
			j++;
		}
		tetris->shape[i][j] = 0;
		i++;
	}
	return (ft_trim_tetris(tetris));
}

int		read_file(int fd, t_tetris *tetris)
{
	int			oct_read;
	char		*sample;
	int			nb_tetris;

	if (!(sample = ft_strnew(BUFF_SIZE)))
		return (0);
	nb_tetris = 0;
	while ((oct_read = read(fd, sample, BUFF_SIZE)))
		if (check_tetris_format(sample))
		{
			if (tetris)
			{
				if (!(tetris->next = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
					return (0);
				tetris->next->prev = tetris;
				tetris = tetris->next;
			}
			else
				if (!(tetris = (t_tetris *)ft_memalloc(sizeof(t_tetris))))
					return (0);
			if (make_tetris(tetris, sample))
				tetris->pos = nb_tetris++;
		}
		else
			return (0);
	free(sample);
	return (nb_tetris);
}
// POS TO BE REDONE

int		main(int argc, char **argv)
{
	int			fd;
	int			size;
	t_tetris	**tetris;
	char		**ans;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1 && (tetris = (t_tetris**)ft_memalloc(sizeof(t_tetris*))))
		{
			*tetris = NULL;
			size = ft_greaterroot(read_file(fd, *tetris));
			close(fd);
			if (size)
			{
				ans = solve(*tetris, size);
				// PRINT ANS;
				return (0);
			}
		}
	}
	ft_putendl("error");
	return (0);
}
