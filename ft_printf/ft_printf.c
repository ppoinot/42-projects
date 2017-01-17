/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:39:02 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/04 11:32:26 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list		aprtf;
	char		*format_cpy;
	t_info		*list;
	int 		nb;

	if (!format)
	{
		ft_putendl("First parameter is NULL. Please don't do this.");
		return (-1);
	}
	format_cpy = ft_strdup(format);
	if (!(list = (t_info*)malloc(sizeof(t_info))))
		ft_putendl_fd("Insufficient storage space is available.", -1);
	va_start(aprtf, format);
	list->nb_c_written = 0;
	list->nb_c_needed = 0;
	list->tmp = NULL;
	list->converted_string = NULL;
	nb = inscribe(format_cpy, &aprtf, list);
	write(1, list->converted_string, nb);
	free(list);
	va_end(aprtf);
	free(format_cpy);
	return (0);
}
