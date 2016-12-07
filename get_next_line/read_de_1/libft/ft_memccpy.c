/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:49:54 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/14 00:15:23 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*p_dst;
	const char	*p_src = src;

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
