/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:55:47 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/09 18:51:14 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(char const *s, char c)
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

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		n;

	if (!s || !c)
		return (NULL);
	i = 0;
	n = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * ft_counter(s, c) + 1)))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		while (s[i] != c && s[i])
			i++;
		if (i && (s[i] == c || s[i] == '\0'))
			tab[n++] = ft_strsub(s, 0, i);
		s += i;
		i = 0;
	}
	tab[n] = NULL;
	return (tab);
}
