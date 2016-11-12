/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:33:47 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/12 10:46:16 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*lire_un_fd(int fd)
{
	char			*sentence;
	static char		*buff_temp = NULL;
	int				nb_oc_lu;
	int				i;

	i = 0;
	nb_oc_lu = 1;
	while (nb_oc_lu != 0)
	{
		if (!(buff_temp = (char*)malloc(sizeof(char) * BUFF_SIZE))
				|| !(nb_oc_lu = read(fd, buff_temp, BUFF_SIZE))
				|| !(sentence = (char*)malloc(sizeof(char) * BUFF_SIZE)))
			return (NULL);
		while (buff_temp[i] && buff_temp[i] != '\n')
		{
			sentence[i] = buff_temp[i];
			i++;
		}
		sentence = ft_realloc(sentence, i);
		if ((i != nb_oc_lu && nb_oc_lu != BUFF_SIZE) || nb_oc_lu == 0)
		{
//			ft_putstr("buff_temp = ");
//			ft_putendl(buff_temp);
			*buff_temp = buff_temp[i + 1];
//			ft_putstr("sentence = ");
//			ft_putendl(sentence);
			return (sentence);
		}
		sentence = ft_realloc(sentence, i + BUFF_SIZE);
		buff_temp = ft_realloc(buff_temp, i + BUFF_SIZE);
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	if (!BUFF_SIZE)
		return (0);
	*line = lire_un_fd(fd);
	if (!*line)
		return (0);
	return (1);
}

int		main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
		ft_putendl(line);
		free(line);
	}
	close(fd);
	return (1);
}
