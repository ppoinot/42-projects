/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inscribe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:07:00 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/17 18:04:04 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	inscribe_final(t_flags *flag, va_list *aprtf, t_info *list)
{
	if (is_a_conversion_specifier(flag->conv_spe))
	{
		if (is_an_alphabetic_flag(flag->conv_spe))
			select_c_s_or_hash(flag, aprtf, list);
		else
			//select_di_ouxX_eE_fF_gG_aA(flag, aprtf, list);
			return ;
	}
}

char	*flag_found(char *str, va_list *aprtf, t_info *list)
{
	t_flags		*flag;

	flag = init_flags();
	str = ft_printf_checkflag(str, flag);
	if (flag->conv_spe)
		inscribe_final(flag, aprtf, list);
	free(flag);
	return (str);
}

int		inscribe(char *string, va_list *aprtf, t_info *list)
{
	if (!(list->converted_string = ft_memalloc(1)))
		return (0);
	while (*string != '\0')
	{
		if (*string == '%')
			string = flag_found(++string, aprtf, list);
		else
		{
			list->converted_string = ft_realloc(list->converted_string, 
				ft_strlen(list->converted_string) + 1);
			list->converted_string[list->nb_c_written++] = *string;
		}
		string++;
	}
	list->converted_string[list->nb_c_written] = '\0';
	return (list->nb_c_written);
}