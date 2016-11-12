/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:19:25 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/12 10:06:49 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		nb_de_ligne(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i - 2);
}

void	*debug(char **tableau)
{
	int		i;

	i = 0;
	while (tableau[i])
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("] : ");
		ft_print_whitespace(tableau[i++]);
	}
	return (NULL);
}

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
			buff_1 = ft_realloc(buff_1, ft_strlen(buff_1) + nb_oc_lu);
			ft_strcat(buff_1, buff_2);
		}
		else {
			if (!(buff_2 = (char*)malloc(sizeof(char) * BUFF_SIZE))
					|| (nb_oc_lu = read(fd, buff_2, BUFF_SIZE)) == -1)
				return (NULL);
			buff_1 = ft_realloc(buff_1, ft_strlen(buff_1) + nb_oc_lu);
			ft_strcat(buff_1, buff_2);
			nb_oc_lu = 0;
		}
	free(buff_2);
	}
	return (buff_1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buff_1 = NULL;
	char			**tab = NULL;
	static int		i = 0;
	int				n;

	if (!BUFF_SIZE)
		return (0);
	if (!buff_1)
		buff_1 = lire_un_fichier(fd);
	//ft_putstr("i =  ");
	//ft_putnbr(i);
	//ft_putchar('\n');
	//TESTER TAB
	tab = ft_strsplit(buff_1, '\n');
	n = nb_de_ligne(tab);
	//ft_putnbr(n + 22);
	//ft_putendl(" -> N");
	debug(tab);
	//ft_putstr("buff 1 = ");
	//ft_print_whitespace(buff_1);
	//ft_putstr("-----------------------------------\n");
	if (i <= n + 1 && *line)
	{
		tab[i] = ft_realloc(tab[i], ft_strlen(tab[i]) - 1);
		*line = tab[i];
		i++;
		return (1);
	}
//	free(buff_1);
	free(tab);
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
	//ft_putnbr(BUFF_SIZE);
	//ft_putendl(" de buffer");
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
		ft_putendl(line);
		free(line);
	}
	close(fd);
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
