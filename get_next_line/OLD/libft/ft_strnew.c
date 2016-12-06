/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:55:23 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/10 04:55:24 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fraiche;

	fraiche = (char *)ft_memalloc(size + 1);
	if (!fraiche)
		return (NULL);
	fraiche[size + 1] = '\0';
	return (fraiche);
}
