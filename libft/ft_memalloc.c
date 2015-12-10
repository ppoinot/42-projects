/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:49:25 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/10 04:49:42 by ppoinot          ###   ########.fr       */
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
