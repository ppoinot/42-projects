/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:47:27 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/10 04:47:31 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	int		fd;
void
	fd = -1;
	fd = open("sample.fillit", O_RDONLY);
	if (fd != -1)
	{
		if (close(fd) == -1)
		{
			ft_putstr("close() error");
			return (0);
		}
		return(1);
	}
	return (0);
}
