/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 03:47:34 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/08 02:38:27 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_compteur(char const *s, char c)
{
	int		n;
	int		index;

	n = 0;
	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (s[index] != c && s[index])
			index++;
		n++;
		s += index;
	}
	return (n);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nbr;
	int		i;
	int		n;

	i = 0;
	n = 0;
	nbr = ft_compteur(s, c);
	tab = (char **)malloc(sizeof(char *) * nbr + 1);
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		while (s[i] != c && s[i])
			i++;
		if (i && s[i] == c)
			tab[n++] = ft_strsub(s, 0, i--);
		printf("i = %d\n", i);
		s += i;
	}
	tab[n] = NULL;
	return (tab);
}

int		main(void)
{
	char	**tab;

	tab = ft_strsplit("**salut**bonjour*", '*');
	printf("Tab[0] = %s\n", tab[0]);
	printf("Tab[1] = %s\n", tab[1]);
	printf("Resultat de ft_strcmp en tab[0] = %d\n", ft_strcmp(tab[0], "salut"));
	return (0);
}
