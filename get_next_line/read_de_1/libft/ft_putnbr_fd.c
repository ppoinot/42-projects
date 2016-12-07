/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 03:59:26 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/14 04:33:15 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putunbr_fd((n / 10), fd);
	n = (n % 10) + '0';
	write(fd, (unsigned char*)(&n), 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putunbr_fd((unsigned int)(-n), fd);
	}
	else
		ft_putunbr_fd((unsigned int)(n), fd);
}
