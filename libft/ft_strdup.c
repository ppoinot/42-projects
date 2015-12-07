/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:11:03 by ppoinot           #+#    #+#             */
/*   Updated: 2015/11/25 21:53:20 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = (char*)malloc(sizeof(*str) * i);
	if (str)
	{
		while (i--)
			str[i] = s[i];
		return (str);
	}
	else
		return (NULL);
}
