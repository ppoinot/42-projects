/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:53:22 by ppoinot           #+#    #+#             */
/*   Updated: 2016/12/16 03:00:10 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>

typedef struct		s_info
{
	int				nb_c_written;
	int				nb_c_needed;
	int 			i;
	char			*tmp;
	char			*converted_string;
}					t_info;

typedef struct 		s_flags
{
	char			conv_spe;
	char			lenth;
	int 			precision;
	
}					t_flags;

char	*is_there_precision(char *str, t_flags *flag);

int 	is_an_alphabetic_flag(char c);
int		is_a_conversion_specifier(char c);
int		is_a_lenth_modifier(char c);
int		is_a_good_flag(char *str);

t_flags	*init_flags(void);

char	*get_lenth_modifier(t_flags *flag, char *str);
char	*get_conversion_specifier(t_flags *flag, char *str);

char	*ft_printf_checkflag(char *str, t_flags *flag);

void	print_final(t_flags *flag, va_list *aprtf, t_list *list);

void	inscribe_c_var(va_list *aprtf, t_info *list);
void	inscribe_C_var(va_list *aprtf, t_info *list);
void	inscribe_s_var(va_list *aprtf, t_info *list, t_flags *flag);
void	inscribe_S_var(va_list *aprtf, t_info *list, t_flags *flag);
void	inscribe_di_var(va_list *aprtf, t_info *list);
void	inscribe_o_var(va_list *aprtf, t_info *list, t_flags *flag);
void	inscribe_u_var(va_list *aprtf, t_info *list, t_flags *flag);
void	inscribe_x_var(va_list *aprtf, t_info *list, t_flags *flag);
void	inscribe_X_var(va_list *aprtf, t_info *list, t_flags *flag);

void	select_cC_sS_or_hash(t_flags *flag, va_list *aprtf, t_info *list);
void	select_di_ouxX_eE_fF_gG_aA(t_flags *flag, va_list *aprtf, t_info *list);

void	inscribe_final(t_flags *flag, va_list *aprtf, t_info *list);
char	*flag_found(char *str, va_list *aprtf, t_info *list);
int		inscribe(char *string, va_list *aprintf, t_info *list);

int		ft_printf(char *format, ...);

/*get_type
***	void va_start(va_list ap, last); 
***	type va_arg(va_list ap, type); 
***	void va_end(va_list ap);
*/

#endif