/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:39:02 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/04 11:32:26 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*is_there_precision(char *str, t_flags *flag)
{
	char	*pre_string;
	int 	i;

	pre_string = ft_strnew(1);
	i = 0;
	while (ft_isdigit((int)*str))
		str++;
	if (*str == '.')
	{
		str++;
		while (*str && ft_isdigit((int)*str))
		{
			pre_string = ft_realloc(pre_string, ft_strlen(pre_string) + 1);
			pre_string[i++] = *str++;
		}
		flag->precision = ft_atoi(pre_string);
	}
	ft_strdel(&pre_string);
	return (str);
}