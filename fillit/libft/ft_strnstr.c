/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:22:06 by vcharles          #+#    #+#             */
/*   Updated: 2015/12/31 19:22:43 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i1;
	size_t	i2;
	size_t	i3;

	i1 = 0;
	if (!small[0])
		return (char *)(big);
	while (big[i1] && i1 < len)
	{
		i2 = i1;
		i3 = 0;
		while (big[i2] == small[i3] && (i2 < len))
		{
			i2++;
			i3++;
			if (small[i3] == 0)
				return (char *)(&big[i1]);
		}
		i1++;
	}
	return (NULL);
}
