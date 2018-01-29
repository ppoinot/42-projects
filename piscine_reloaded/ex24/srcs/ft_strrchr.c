/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:55:37 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/14 04:21:22 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		while (i >= 0)
		{
			if (s[i] == (unsigned char)c)
				return ((char *)(s + i));
			i--;
		}
	}
	else if (c == '\0')
		return (((char *)s + ft_strlen(s)));
	return (NULL);
}
