/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:26:52 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/03 13:40:51 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ans;
	int		bck;
	int		size;

	bck = n;
	size = 1;
	while ((n = n / 10))
		size++;
	if (bck < 0)
		size++;
	n = bck;
	ans = ft_strnew(size);
	if (ans)
	{
		ans[size] = 0;
		while (size--)
		{
			ans[size] = ft_abs(bck % 10) + '0';
			bck = bck / 10;
		}
		if (n < 0)
			ans[0] = '-';
	}
	return (ans);
}
