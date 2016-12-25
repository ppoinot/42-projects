/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 03:19:22 by ppoinot           #+#    #+#             */
/*   Updated: 2016/12/16 03:00:10 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct		s_info
{
	int				nb_c_written;
	int				nb_c_needed;
	char			*tmp;
	char			*converted_string;
}					t_info;

int		ft_printf(char *format, ...);

/*
***	void va_start(va_list ap, last); 
***	type va_arg(va_list ap, type); 
***	void va_end(va_list ap);
*/

#endif