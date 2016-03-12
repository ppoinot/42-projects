/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 16:10:30 by vcharles          #+#    #+#             */
/*   Updated: 2015/12/30 18:39:48 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	while (s1[i1])
		i1++;
	while (i2 < n)
	{
		s1[i1] = s2[i2];
		i1++;
		i2++;
	}
	s1[i1] = 0;
	return (s1);
}