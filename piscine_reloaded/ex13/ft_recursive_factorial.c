/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 17:08:01 by ppoinot           #+#    #+#             */
/*   Updated: 2015/07/15 14:18:53 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb > 1)
	{
		nb = ft_recursive_factorial(nb - 1) * nb;
		return (nb);
	}
	if (nb == 0)
		return (1);
	else
		return (0);
}
