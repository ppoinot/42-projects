/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:51:20 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/10 04:51:21 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *b, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((char*)b)[i] = (char)c;
		i++;
	}
	return (b);
}
