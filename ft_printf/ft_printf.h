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

typedef struct 		s_flags
{
	char			type;
	char			lenth;
	
}					t_flags;

int 	is_an_alphabetic_flag(char c);
int		is_a_conversion_specifier(char c);
int		is_a_lenth_modifier(char c);
int		is_a_good_flag(char *str);

t_flags	*init_flags(void);

char	*get_lenth_modifier(t_flags *flag, char *str);
char	*get_conversion_specifier(t_flags *flag, char *str);

char	*ft_printf_checkflag(char *str, va_list *aprtf, t_info *list,
		t_flags flag);

void	print_final(t_flags *flag, va_list *aprtf, t_list *list);

void	inscribe_final(t_flags *flag, va_list *aprtf, t_info *list);
char	*flag_found(char *str, va_list *aprtf, t_info *list);
int		inscribe(char *string, va_list *aprintf, t_info *list);

int		ft_printf(char *format, ...);

/*
***	void va_start(va_list ap, last); 
***	type va_arg(va_list ap, type); 
***	void va_end(va_list ap);
*/

#endif