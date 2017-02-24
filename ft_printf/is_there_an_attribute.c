/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_an_attribute.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:39:02 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/04 11:32:26 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_attribute_hash_to_format(t_flags *flag, t_info *list)
{
	if (flag->conv_spe == 'o')
		{
			list->converted_string = ft_realloc(list->converted_string,
			ft_strlen(list->converted_string) + 1);
			list->converted_string[list->nb_c_written++] = '0';
		}
		else if (flag->conv_spe == 'x' || flag->conv_spe == 'X')
		{
			list->converted_string = ft_realloc(list->converted_string,
			ft_strlen(list->converted_string) + 2);
			list->converted_string[list->nb_c_written++] = '0';
			if (flag->conv_spe == 'x')
				list->converted_string[list->nb_c_written++] = 'x';
			else if (flag->conv_spe == 'X')
				list->converted_string[list->nb_c_written++] = 'X';
		}
	return ;
}

char	*is_there_an_attribute(char *str, t_flags *flag)
{
	if (is_an_attribute(*str))
		flag->attribute = *str;
	return (str++);
}