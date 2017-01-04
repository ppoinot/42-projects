/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:43:18 by ppoinot           #+#    #+#             */
/*   Updated: 2016/02/12 16:43:23 by ppoinot          ###   ########.fr       */
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
