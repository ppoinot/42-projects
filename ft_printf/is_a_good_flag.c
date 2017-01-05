/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_good_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:39:02 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/04 11:32:26 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	is_a_conversion_specifiers(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' 
		|| c == 'X' || c == 'D' || c == 'O' || c == 'U' || c == 'e' 
		|| c == 'E' || c == 'f' || c == 'F' || c == 'g' || c == 'G'
		|| c == 'a' || c == 'A' || c == 'C' || c == 'c' || c == 'S'
		|| c == 's' || c == 'p' || c == 'n' || c == '%')
		return (1);
	else 
		return (0);
}

int 	is_a_lenth_modifier(char c)
{
	if(c == 'h' || c == 'l' || c == 'L' || c == 'j' || c == 'z' || c == 't')
		return (1);
	else
		return (0);
}

int		is_a_good_flag(char *str)
{
	if (is_a_conversion_specifiers(*str) || is_a_lenth_modifier(*str)
		|| ft_isdigit(*str))
		return (1);
	else 
		return (0);
}
