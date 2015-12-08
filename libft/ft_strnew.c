/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:12:22 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/08 01:50:08 by ppoinot          ###   ########.fr       */
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
