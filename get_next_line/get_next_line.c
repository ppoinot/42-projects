/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:19:25 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/08 18:11:35 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*lire_un_fichier(int fd)
{
	char	*buff_1;
	char	*buff_2;
	int		nb_oc_lu;

	if (!(buff_1 = (char*)malloc(sizeof(char) * BUFF_SIZE))
			|| !(nb_oc_lu = read(fd, buff_1, BUFF_SIZE)))
		return (NULL);
	while (nb_oc_lu != 0)
	{
		if (nb_oc_lu == BUFF_SIZE)
		{
			if (!(buff_2 = (char*)malloc(sizeof(char) * BUFF_SIZE))
					|| (nb_oc_lu = read(fd, buff_2, BUFF_SIZE)) == -1)
				return (NULL);
			buff_1 = ft_realloc(buff_1, ft_strlen(buff_1) + nb_oc_lu + 1);
			ft_strcat(buff_1, buff_2);
		}
		else {
			if (!(buff_2 = (char*)malloc(sizeof(char) * BUFF_SIZE))
					|| (nb_oc_lu = read(fd, buff_2, BUFF_SIZE)) == -1)
				return (NULL);
			buff_1 = ft_realloc(buff_1, ft_strlen(buff_1) + nb_oc_lu + 1);
			ft_strcat(buff_1, buff_2);
			nb_oc_lu = 0;
		}
	free(buff_2);
	}
	return (buff_1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buff_1;
	char			**tab;
	int				n;
	static int		i;

	if (!BUFF_SIZE)
		return (0);
	if (!buff_1)
		buff_1 = lire_un_fichier(fd);
	n = ft_nbocc(buff_1, '\n');
	tab = ft_strsplit(buff_1, '\n');
	//free(buff_1);
	*line = tab[i++];
	if (i < n)
		return (1);
	free(buff_1);
	return (0);
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
	ft_putchar('\n');
	ft_putnbr(BUFF_SIZE);
	ft_putendl(" de buffer");
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
		ft_putendl(line);
		free(line);
	}
	return (1);
}
/*
   1- allouer un buffer de taille TAILLE
   2- tant que lire un caractère n'atteint pas la fin de fichier et que le 
   caractère lu est différent de \'n'
   Stocker le caractère lu dans buffer[i]
   2.5- si buffer est trop petit, tu realloc.
   fin_tant_que
   3- une fois que tu as lu une ligne, tu:
   char *resultat =strdup(buffer)
   free(buffer)
   return resultat;
   */
