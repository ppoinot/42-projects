/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:53:43 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/14 00:40:51 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = (char*)malloc(sizeof(*str) * i + 1);
	if (!str)
		return (NULL);
	else
	{
		str[i] = '\0';
		while (i--)
			str[i] = s[i];
		return (str);
	}
}
