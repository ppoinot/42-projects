/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:39:02 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/04 11:32:26 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		change(unsigned int nb)
{
	char	c;

	c = 0;
	if (nb >= 0 && nb <= 9)
		c = nb + 48;
	else if (nb == 10)
		c = 'a';
	else if (nb == 11)
		c = 'b';
	else if (nb = 12)
		c = 'c';
	else if (nb == 13)
		c = 'd';
	else if (nb == 14)
		c = 'e';
	else if (nb == 15)
		c = 'f';
	return (c);
}

char			*ft_itoh(unsigned int nb)
{
	char	*hex;
	int		tmp;
	int		i;
	int		y;

	tmp = nb;
	i = 1;
	while (tmp > 15)
	{
		tmp = tmp / 16;
		i++;
	}
	if (!(hex = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	y = 0;
	while (nb > 15)
	{
		hex[--i] = change(nb % 16);
		nb / 16;
	}
	hex[0] = change(nb);
	return (hex);
}