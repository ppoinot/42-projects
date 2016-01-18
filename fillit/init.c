/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:04:24 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/18 11:30:59 by ppoinot          ###   ########.fr       */
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
		if ((i + 1) % 5 && (str[i] != '.' && str[i] != '#'))
			return (0);
		if (!((i + 1) % 5) && str[i] != '\n')
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

int		read_file(int fd, t_tetris *tetris)
{
	int			oct_read;
	char		*sample;
	int			nb_tetris;
	int			test_boucle;

	test_boucle = 0;
	nb_tetris = 'A';
	while (!test_boucle)
	{
		if (!(sample = ft_strnew(20)))
			return (0);
		if ((oct_read = read(fd, sample, 20)) != 20)
			return (0);
		if (!check_tetris_format(sample))
			return (0);
		if (!make_tetris(tetris, sample))
			return (0);
		free(sample);
		nb_tetris += 1;
		if (!(sample = ft_strnew(1)))
			return (0);
		if ((oct_read = read(fd, sample, 1)) != 1)
			return (0);
		if (*sample != '\n')
		{
			if (*sample == '\0')
				test_boucle++;
			else
				return (0);
		}
		free(sample);
	}
	return (nb_tetris - 'A');
/*	while ((oct_read = read(fd, sample, BUFF_SIZE)))
	{
		if (check_tetris_format(sample))
		{
			if (tetris)
			{
				if (!(tetris->next = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
					return (0);
				tetris->next->prev = tetris;
				tetris = tetris->next;
			}
			else if (!(tetris = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
				return (0);
			if (!make_tetris(tetris, sample))
				return (0);
			tetris->pos = nb_tetris++;
		}
		else
			return (0);
		ft_bzero(sample, oct_read);
	i}*/
//	free(sample);
}

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
				print_map(ans, size);
				return (0);
			}
		}
	}
	ft_putendl("error");
	return (0);
}
