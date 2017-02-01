/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inscribe_medium_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:07:00 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/17 18:04:04 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*precision(t_flags *flag, int x)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(flag->precision - x);
	str = ft_memset(str, 48, flag->precision - x);
	return (str);
}

void		inscribe_o_var(va_list *aprtf, t_info *list, t_flags *flag)
{
	unsigned int		cur_arg;
	int 				x;
	int					y;
	int					z;
	int					octal;
	char				*cur_arg_string;

	cur_arg = va_arg(*aprtf, unsigned int);
	x = cur_arg / 64;
	y = cur_arg % 64;
	z = y % 8;
	y = y / 8;
	z = z / 1;
	octal = x * 100 + y * 10 + z * 1;
	cur_arg_string = ft_itoa(octal);
	if ((x = ft_strlen(cur_arg_string)) <= flag->precision)
		cur_arg_string = ft_strjoin(precision(flag, x), cur_arg_string);
	y = 0;
	list->converted_string = ft_realloc(list->converted_string, 
				ft_strlen(list->converted_string) + ft_strlen(cur_arg_string));
	while (y < (int)ft_strlen(cur_arg_string))
		list->converted_string[list->nb_c_written++] = cur_arg_string[y++];
	return ;
}