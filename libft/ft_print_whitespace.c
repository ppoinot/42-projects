/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:47:06 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/09 11:26:07 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_print_whitespace(char *chaine)
{
	int		i;

	i = 0;
	while (chaine[i])
	{
		if (chaine[i] == ' ')
			ft_putchar('*');
		else
			ft_putchar(chaine[i]);
		i++;
	}
	return (NULL);
}
