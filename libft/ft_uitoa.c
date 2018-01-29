/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:49:03 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/14 03:25:24 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*array;

	if (!(array = (char*)malloc(sizeof(char) * 22)))
		return (NULL);
	array[21] = 0;
	array = array + 21;
	if (n == 0)
		*array = n + 48;
	while (n != 0)
	{
		*--array = (n % 10) + 48;
		n /= 10;
	}
	return (array);
}