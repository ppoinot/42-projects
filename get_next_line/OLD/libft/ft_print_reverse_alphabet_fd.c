/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet_fd.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 00:22:41 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/16 00:23:46 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_reverse_alphabet_fd(int fd)
{
	int		i;

	i = 122;
	while (i > 96)
		ft_putchar_fd(i--, fd);
}
