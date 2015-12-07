/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:39:13 by ppoinot           #+#    #+#             */
/*   Updated: 2015/11/24 23:13:50 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*p = s;
	size_t		len;

	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (*p == (char)c)
			return ((char*)p);
		p++;
	}
	return (NULL);
}
