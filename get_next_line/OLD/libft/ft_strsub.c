/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:56:03 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/14 03:22:23 by ppoinot          ###   ########.fr       */
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
	troncon[len] = '\0';
	while (s[start] && len--)
		troncon[i++] = s[start++];
	return (troncon);
}
