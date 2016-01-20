/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:47:27 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/10 04:47:31 by ppoinot          ###   ########.fr       */
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
