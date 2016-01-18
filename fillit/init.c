/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:04:24 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/18 14:11:29 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		make_tetriminos(t_tetris *tetris, char *sample)
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
			return (0);
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

int		create_tetris_struct(t_tetris *tetris)
{
	if (tetris)
	{
		if (!(tetris->next = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
			return (0);
		tetris->next->prev = tetris;
		tetris = tetris->next;
		tetris->next = NULL;
		tetris->pos = tetris->prev->pos + 1;
	}
	else
	{
		if (!(tetris = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
			return (0);
		tetris->prev = NULL;
		tetris->next = NULL;
		tetris->pos = 'A';
	}
	return (1);
}

int		read_file(int fd, t_tetris *tetris)
{
	int			oct_read;
	char		*sample;
	int			eof;

	eof = 0;
	if (!(sample = ft_strnew(20)))
		return (0);
	while (!eof)
	{
		if ((oct_read = read(fd, sample, 20)) != 20 ||
				!check_tetris_format(sample) ||
				!create_tetris_struct(tetris) ||
				!make_tetriminos(tetris, sample) ||
				(oct_read = read(fd, sample, 1)) != 1)
		{
			free(sample);
			return (0);
		}
		if (*sample != '\n' && *sample != '\0')
			return (0);
		if (*sample == '\0')
			eof++;
	}
	free(sample);
	return (tetris->pos - 'A' + 1);
}

int		main(int argc, char **argv)
{
	int			fd;
	int			size;
	t_tetris	**tetris;

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
				solve(*tetris, size);
				return (0);
			}
			cleanup(*tetris);
			free(tetris);
		}
	}
	ft_putendl("error");
	return (0);
}
