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

void	inscribe_final(t_flags *flag, va_list *aprtf, t_info *list)
{
	if (is_a_conversion_specifier(flag->type))
	{
		/*if (is_an_alphabetic_flag(flag->type))
			// display_alpha_var(flag, aprtf, list);
		else
			//display_numeric_var(flag, aprtf, list);*/
	}
}

char	*flag_found(char *str, va_list *aprtf, t_info *list)
{
	t_flags		*flag;

	flag = init_flags();
	str = ft_printf_checkflag(str, aprtf, list, *flag);
	if (flag->type)
		//print_final(flag, aprtf, list);
	free(flag);
	return (str);
}

int		inscribe(char *string, va_list *aprtf, t_info *list)
{
	while (*string != '\0')
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