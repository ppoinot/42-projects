/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 03:47:34 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/07 03:29:32 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if (i)
			tab[n++] = ft_strcpy(ft_strnew(i), s);
		s += i;
	}
	tab[n] = NULL;
	return (tab);
}
