/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:51:02 by ppoinot           #+#    #+#             */
/*   Updated: 2015/11/28 00:25:16 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fraiche;

	fraiche = malloc(size);
	if (!fraiche)
		return (NULL);
	ft_memset(fraiche, 0, size);
	return (fraiche);
}
