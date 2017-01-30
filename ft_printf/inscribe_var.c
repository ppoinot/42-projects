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

void	inscribe_alpha_var(t_flags *flag, va_list *aprtf, t_info *list)
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