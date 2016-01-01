/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:54:38 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/14 03:20:43 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fraiche;

	i = -1;
	fraiche = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!fraiche)
		return (NULL);
	fraiche[ft_strlen(s)] = '\0';
	while (s[++i])
		fraiche[i] = f(s[i]);
	return (fraiche);
}
