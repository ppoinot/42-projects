/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:24:27 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/10 00:49:30 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	size_origin;

	size_origin = size;
	len_dest = ft_strlen(s1);
	len_src = ft_strlen(s2);
	while (*s1 && size)
	{
		s1++;
		size--;
	}
	if (!size)
		return (size_origin + len_src);
	while (*s2 && size-- > 1)
		*s1++ = *s2++;
	*s1 = '\0';
	return (len_dest + len_src);
}
