/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:19:25 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/07 08:06:12 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*lire_un_fichier(int fd)
{
	char	*buff_1;
	char	*buff_2;
	char	*sentence;
	int		x;
	int		nb_oc_lu;

	if (!(buff_1 = (char*)malloc(sizeof(char) * BUFF_SIZE))
			|| (nb_oc_lu = read(fd, buff_1, BUFF_SIZE)) == -1
			|| !(sentence = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	x = nb_oc_lu;
	while (nb_oc_lu == BUFF_SIZE)
	{
		buff_1 = ft_realloc(buff_1, ft_strlen(buff_1) + BUFF_SIZE);
		if (!(buff_2 = (char*)malloc(sizeof(char) * BUFF_SIZE))
				|| (nb_oc_lu = read(fd, buff_2, BUFF_SIZE)) == -1)
			return (NULL);
		ft_strcat(buff_1, buff_2);
	}
	return (buff_1);
}

int		get_next_line(const int fd, char **line)
{
	char	c;
	char	*buff_1;
	char	*sentence;
	int		i;
	int		nb_oc_lu;

	i = 0;
	c = buff_1[i];
	while(c != '\n' && i != nb_oc_lu)
	{
		sentence[i] = c;
		c = buff_1[i++];
		i++;
	}

	return (buff_1);
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
