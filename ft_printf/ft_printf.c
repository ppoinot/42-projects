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

static	t_info	*init_info_list(void)
{
	t_info		*new_list;

	if (!(new_list = (t_info*)malloc(sizeof(t_info))))
	{
		ft_putendl("Insufficient storage space is available.");
		return (NULL);
	}
	new_list->nb_c_written = 0;
	new_list->nb_c_needed = 0;
	new_list->i = 0;
	new_list->tmp = NULL;
	new_list->converted_string = NULL;
	return (new_list);
}

int		ft_printf(char *format, ...)
{
	va_list		aprtf;
	char		*format_cpy;
	t_info		*list;
	int 		ret;

	if (!format || *format == 0)
	{
		ft_putendl("First parameter is NULL. Please don't do this.");
		return (-1);
	}
	format_cpy = ft_strdup(format);
	va_start(aprtf, format);
	if (!(list = init_info_list()))
		return (-1);
	ret = inscribe(format_cpy, &aprtf, list);
	write(1, list->converted_string, ret);
	free(list);
	va_end(aprtf);
	free(format_cpy);
	return (ret);
}
