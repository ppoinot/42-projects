/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 16:18:32 by vcharles          #+#    #+#             */
/*   Updated: 2015/12/31 19:16:15 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*str;
	size_t	len;

	if (!(str = ft_memchr(dst, 0, size)))
		return (size + ft_strlen(src));
	len = (size_t)(str - dst) + ft_strlen(src);
	while (*src && (size_t)(str - dst) + 1 < size)
	{
		*str = *src;
		str++;
		src++;
	}
	*str = 0;
	return (len);
}
