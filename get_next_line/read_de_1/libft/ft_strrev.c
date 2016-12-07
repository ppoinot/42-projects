/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 00:27:39 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/16 01:00:28 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	c;
	int		i;
	int		len;

	if (str)
	{
		i = 0;
		len = (ft_strlen(str) - 1);
		while (i < len / 2)
		{
			c = str[i];
			str[i] = str[len - i];
			str[len - i] = c;
			i++;
		}
		return (str);
	}
	return (NULL);
}
