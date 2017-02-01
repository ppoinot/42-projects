/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:07:00 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/17 18:04:04 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	select_cC_sS_or_hash(t_flags *flag, va_list *aprtf, t_info *list)
{
	if (flag->conv_spe == 'c')
		inscribe_c_var(aprtf, list);
	else if (flag->conv_spe == 'C')
		inscribe_C_var(aprtf, list);
	else if (flag->conv_spe == 's')
		inscribe_s_var(aprtf, list, flag);
	else if (flag->conv_spe == 'S')
		inscribe_S_var(aprtf, list, flag);
	else
	{
		list->converted_string = ft_realloc(list->converted_string,
			ft_strlen(list->converted_string) + 1);
		list->converted_string[list->nb_c_written++] = '%';
	}
}

void	select_di_ouxX_eE_fF_gG_aA(t_flags *flag, va_list *aprtf, t_info *list)
{
	if (flag->conv_spe == 'd' || flag->conv_spe == 'i')
		inscribe_di_var(aprtf, list);
	else if (flag->conv_spe == 'o')
		inscribe_o_var(aprtf, list);
	else if (flag->conv_spe == 'u' || flag->conv_spe == 'x' 
		|| flag->conv_spe == 'X')
	return ;
}