/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:51:59 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/03 12:52:01 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compteur(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s && *s != c)
			s++;
		count++;
		s++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		n;

	if (!s)
		return (NULL);
	n = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * ft_compteur(s, c) + 1);
	if (tab)
	{
		while (*s)
		{
			while (*s == c)
				s++;
			i = 0;
			while (s[i] != c && s[i])
				i++;
			if (i && (s[i] == c || s[i] == '\0'))
				tab[n++] = ft_strsub(s, 0, i);
			s = s + i;
		}
		tab[n] = NULL;
	}
	return (tab);
}
