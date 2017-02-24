/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_thing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:39:02 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/04 11:32:26 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	is_an_attribute(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+')
		return (1);
	else
		return (0);	
}

int 	is_an_alphabetic_flag(char c)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == '%')
		return (1);
	else
		return (0);
}

int 	is_a_conversion_specifier(char c)
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
	if(c == 'h' || c == 'l' || c == 'L' || c == 'j' || c == 'z')
		return (1);
	else
		return (0);
}

int		is_a_good_flag(char *str)
{
	if (is_a_conversion_specifier(*str) || is_a_lenth_modifier(*str)
		|| ft_isdigit(*str) || is_an_attribute(*str))
		return (1);
	else 
		return (0);
}
