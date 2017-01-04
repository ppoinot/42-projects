/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 03:19:22 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/04 14:56:12 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_info
{
	int				ret_ft_printf;
	char			*tmp;
	char			*converted_string;
}					t_info;

int		ft_printf(char *format, ...);

/*
***	void va_start(va_list ap, last); debute la recuperation de la liste
***	type va_arg(va_list ap, type); recupere l'argument actuellement "pointe"
***	void va_end(va_list ap); termine la recuperation de la liste
*/

#endif
