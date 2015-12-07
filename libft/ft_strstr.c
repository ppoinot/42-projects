/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:28:32 by ppoinot           #+#    #+#             */
/*   Updated: 2015/11/30 02:56:13 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		len;

	len = ft_strlen(s2);
	if (!len)
		return ((char*)s1);
	while (*s1)
	{
		if (!ft_memcmp(s1, s2, len))
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
