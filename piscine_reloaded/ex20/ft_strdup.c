/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:53:43 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/14 13:35:16 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = ft_strlen(src);
	str = (char*)malloc(sizeof(*str) * i + 1);
	if (!str)
		return (NULL);
	else
	{
		str[i] = '\0';
		while (i--)
			str[i] = src[i];
		return (str);
	}
}
