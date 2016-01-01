/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:52:05 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/14 04:32:57 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putunbr(unsigned int n)
{
	if (n > 9)
		ft_putunbr(n / 10);
	n = (n % 10) + '0';
	write(1, (unsigned char*)(&n), 1);
}

void		ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		ft_putunbr((unsigned int)(-n));
	}
	else
		ft_putunbr((unsigned int)(n));
}
