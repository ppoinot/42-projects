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
			inscribe_alpha_var(flag, aprtf, list);
		else
			//display_numeric_var(flag, aprtf, list);*/ 
			return ;
	}
}

/*char	*add_to_format(char *str)
{
	char	*cur_arg;

	cur_arg = va_arg(aprtf, char*);
	str = ft_printf_strjoin();
	return (str);
}*/

char	*flag_found(char *str, va_list *aprtf, t_info *list)
{
	t_flags		*flag;

	flag = init_flags();
	str = ft_printf_checkflag(str, aprtf, list, *flag);
	if (flag->conv_spe)
		inscribe_final(flag, aprtf, list);
	free(flag);
	return (str);
}

int		inscribe(char *string, va_list *aprtf, t_info *list)
{
	if (!(list->converted_string = ft_memalloc(50)))
		return (0);
	while (*string != '\0')
	{
		if (*string == '%')
			string = flag_found(++string, aprtf, list);
		//realloc list->converted_string pour ajouter le cur_arg;
		else
		{
			//printf("%c\n", *string);
			list->converted_string[list->nb_c_written++] = *string;
			string++;
		}
	}
	list->converted_string[list->nb_c_written] = '\0';
	return (list->nb_c_written);
}