/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:35:00 by ppoinot           #+#    #+#             */
/*   Updated: 2015/11/24 00:24:27 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*p_dst;
	const char	*p_src = src;

	if (!dst || !src)
		return (NULL);
	p_dst = dst;
	while (n--)
	{
		*p_dst++ = *p_src;
		if (*p_src == (char)c)
			return (p_dst);
		p_src++;
	}
	return (NULL);
}
