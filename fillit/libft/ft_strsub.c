/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 16:19:13 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/14 15:07:54 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s || !s[start] || start >= ft_strlen(s))
		return (NULL);
	str = ft_strnew(len);
	if (str)
	{
		i = 0;
		s = s + start;
		while (*s && len--)
			str[i++] = *(s++);
	}
	return (str);
}
