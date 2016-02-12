/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 14:04:24 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/01 19:01:29 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str)
		{
			i = 0;
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
			str[i] = 0;
			return (str);
		}
	}
	return (NULL);
}
