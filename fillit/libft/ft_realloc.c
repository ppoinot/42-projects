/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 14:53:31 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/08 17:32:19 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*dst;

	if (!(dst = ft_memalloc(size)))
		return (ptr);
	if (ptr)
	{
		ft_memcpy(dst, ptr, size);
		free(ptr);
	}
	return (dst);
}
