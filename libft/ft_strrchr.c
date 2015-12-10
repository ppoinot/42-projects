/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:55:37 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/10 04:55:38 by ppoinot          ###   ########.fr       */
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
