/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:54:53 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/10 04:54:54 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *dest_start;

	dest_start = dest;
	while (*dest)
		++dest;
	++n;
	while (--n && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}
