/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 19:58:00 by ppoinot           #+#    #+#             */
/*   Updated: 2016/12/25 20:42:21 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*init_flags(void)
{
	t_flags		*current_flag;
	
	if (!(current_flag = (t_flags*)malloc(sizeof(t_flags))))
		return(NULL);
	current_flag->type = 0;
	current_flag->lenth = 0;
	return (current_flag);
}