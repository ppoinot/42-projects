/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:02:40 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/07 01:12:29 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*troncon;
	int		i;

	i = 0;
	troncon = (char *)malloc(sizeof(char) * (len + 1));
	if (!troncon)
		return (NULL);
	troncon[len + 1] = '\0';
	while (s[start] && len--)
		troncon[i++] = s[start++];
	return (troncon);
}
