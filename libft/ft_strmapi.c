/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:54:45 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/14 03:21:47 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fraiche;

	i = -1;
	if (!s || !f)
		return (NULL);
	if (!(fraiche = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	fraiche[ft_strlen(s)] = '\0';
	while (s[++i])
		fraiche[i] = f(i, s[i]);
	return (fraiche);
}
