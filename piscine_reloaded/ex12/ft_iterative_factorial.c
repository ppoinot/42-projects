/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 16:14:58 by ppoinot           #+#    #+#             */
/*   Updated: 2015/07/13 17:06:29 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int	a;

	a = 1;
	if (nb > 0 && nb < 13)
	{
		while (nb > 1)
		{
			a = a * nb;
			nb--;
		}
		return (a);
	}
	if (nb < 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
