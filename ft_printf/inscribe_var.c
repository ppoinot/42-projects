/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inscribe_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:07:00 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/17 18:04:04 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	inscribe_c_var(t_flags *flag, va_list *aprtf, t_info *list)
{
	int		cur_arg;

	cur_arg = va_arg(*aprtf, int);
	list->converted_string = ft_realloc(list->converted_string,
			ft_strlen(list->converted_string) + 1);
	list->converted_string[list->nb_c_written++] = cur_arg;
	return ;
}

static void	inscribe_s_var(t_flags *flag, va_list *aprtf, t_info *list)
{
	char	*cur_arg;
	int 	i;
	int		y;

	cur_arg = va_arg(*aprtf, char*);
	i = ft_strlen(cur_arg);
	y = 0;
	list->converted_string = ft_realloc(list->converted_string, 
				ft_strlen(list->converted_string) + i);
	while (y < i)
	{
		list->converted_string[list->nb_c_written++] = cur_arg[y];
		y++;
	}
	return ;
}

void	select_c_s_or_hash(t_flags *flag, va_list *aprtf, t_info *list)
{
	if (flag->conv_spe == 'c')
		inscribe_c_var(flag, aprtf, list);
	else if (flag->conv_spe == 's')
		inscribe_s_var(flag, aprtf, list);
	else
	{
		list->converted_string = ft_realloc(list->converted_string,
			ft_strlen(list->converted_string) + 1);
		list->converted_string[list->nb_c_written++] = '%';
	}
}