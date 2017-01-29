/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checkflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:39:02 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/04 11:32:26 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_checkflag(char *str, va_list *aprtf, t_info *list,
		t_flags *flag)
{
	while (is_a_good_flag(str) && (flag->conv_spe == 0))
	{
		if (is_a_conversion_specifier(*str))
			str = get_conversion_specifier(flag, str);
		else if (is_a_lenth_modifier(*str))
			str = get_lenth_modifier(flag, str);
		//else if ();
	}
	return (str);
}