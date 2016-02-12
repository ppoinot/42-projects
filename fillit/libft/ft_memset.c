/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:23:52 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/14 12:06:42 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int input, size_t len)
{
	size_t			i;

	if (ptr)
	{
		i = 0;
		while (i < len)
			((unsigned char *)ptr)[i++] = (unsigned char)input;
	}
	return (ptr);
}
