/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 03:19:22 by ppoinot           #+#    #+#             */
/*   Updated: 2016/12/16 03:00:10 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_lenth_modifier(t_flags *flag, char *str)
{
	flag->lenth_mod[0] = *str;
	if (*str == 'h')
	{
		if (*(str + 1) == 'h')
		{
			flag->lenth_mod[1] = *(str + 1);
			return (str + 2);
		}
	}
	else if (*str == 'l')
	{
		if (*(str + 1) == 'l')
		{
			flag->lenth_mod[1] = *(str + 1);
			return (str + 2);
		}
	}
	return (str++);
}

char	*get_conversion_specifier(t_flags *flag, char *str)
{
	flag->conv_spe = *str;
	return (str++);
}