/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 03:32:51 by ppoinot           #+#    #+#             */
/*   Updated: 2015/11/30 02:58:09 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len;

	len = ft_strlen(s2);
	if (!len)
		return ((char *)s1);
	while (*s1 && len <= n--)
	{
		if (!ft_memcmp(s1, s2, len))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
