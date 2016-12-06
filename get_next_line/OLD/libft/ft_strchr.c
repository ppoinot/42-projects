/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:53:01 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/10 04:53:02 by ppoinot          ###   ########.fr       */
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
