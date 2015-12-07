/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:01:43 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/05 03:29:41 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_occ;

	last_occ = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			last_occ = (char *)s;
		s++;
	}
	if (!*s && *s == (char)c)
		last_occ = (char *)s;
	return ((last_occ) ? last_occ : NULL);
}
