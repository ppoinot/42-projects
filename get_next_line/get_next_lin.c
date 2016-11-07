/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:19:25 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/07 16:38:09 by ppoinot          ###   ########.fr       */
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
	char	*sentence;
	int		nb_oc_lu;

	if (!(buff_1 = (char*)malloc(sizeof(char) * BUFF_SIZE))
			|| (nb_oc_lu = read(fd, buff_1, BUFF_SIZE)) == -1
			|| !(sentence = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	while (nb_oc_lu == BUFF_SIZE)
	{
		buff_1 = ft_realloc(buff_1, ft_strlen(buff_1) + BUFF_SIZE);
		if (!(buff_2 = (char*)malloc(sizeof(char) * BUFF_SIZE))
				|| (nb_oc_lu = read(fd, buff_2, BUFF_SIZE)) == -1)
			return (NULL);
		ft_strcat(buff_1, buff_2);
		free (buff_2);
	}
	return (buff_1);
}

int		get_next_line(const int fd, char **line)
{
	char	*c;
	char	*buff_1;
	char	*sentence;
	static int		i;
	int		nb_oc_lu;

	buff_1 = lire_un_fichier(fd);
	if (!(sentence = (char*)malloc(sizeof(char) * ft_strlen(buff_1))))
		return (-1);
	//*c = buff_1[0];
	line = ft_strsplit(buff_1, '\n');
	i = 0;
	ft_putstr(line[i]);

	i++;

	while(*c != '\n' && i != ft_strlen(buff_1))
	{
		sentence[i] = *c;
		*c = buff_1[i++];
		i++;
	 }
	 if (i != ft_strlen(buff_1))
	 {
	 sentence = ft_realloc(sentence, i);
	 ft_putstr(sentence);
	
	 }
	return (0);
}

int		main(void)
{
	int     fd;
	char    *line;
	int		i;

	fd = open("test", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
		ft_putendl("LINE");
		ft_putendl(line);
		free (line);
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
