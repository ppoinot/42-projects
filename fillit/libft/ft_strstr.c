/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 17:35:28 by vcharles          #+#    #+#             */
/*   Updated: 2015/12/31 19:24:19 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *small)
{
	int		i1;
	int		i2;
	int		i3;

	if (small[0] == 0)
		return ((char *)(big));
	i1 = 0;
	while (big[i1])
	{
		i2 = i1;
		i3 = 0;
		while (big[i2] == small[i3])
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
