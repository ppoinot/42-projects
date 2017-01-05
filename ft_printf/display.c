/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display .c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 03:19:22 by ppoinot           #+#    #+#             */
/*   Updated: 2016/12/16 03:00:10 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_found(char *str, va_list *aprtf, t_list *list)
{
	t_flags		*flag;

	flag = init_flags();
	str = ft_printf_checkflag(str, aprtf, list)
	free(flag);
	return (str);
}

int		display(char *string, va_list *aprtf, t_info *list)
{
	while (*string != '/0')
	{
		if (*string == '%')
			string = flag_found(++string, aprtf, list);
		else
		{
			string++;
		}
	}
	return (list->nb_c_written);
}