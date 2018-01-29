/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:37:15 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/14 14:10:14 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		range;
	int		i;

	range = max - min;
	if (range <= 0)
		return (NULL);
	if (!(tab = (int*)malloc(sizeof(int) * range)))
		return (NULL);
	i = -1;
	while (i++ < range)
		tab[i] = min + i;
	return (tab);
}
