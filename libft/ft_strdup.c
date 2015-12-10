/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:53:43 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/10 04:53:44 by ppoinot          ###   ########.fr       */
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
