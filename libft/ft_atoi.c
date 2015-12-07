/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 23:13:40 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/07 02:51:12 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *nptr)
{
	int		result;
	int		sign;

	result = 0;
	sign = 0;
	while (ft_isspace(*nptr) && *nptr)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			sign = 1;
		nptr++;
	}
	while (*nptr && *nptr >= 48 && *nptr <= 57)
	{
		result = result * 10;
		result = result + (*nptr - 48);
		nptr++;
	}
	if (sign)
		return (-result);
	return (result);
}
