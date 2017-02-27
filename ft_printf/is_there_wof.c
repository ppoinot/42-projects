/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_wof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:39:02 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/04 11:32:26 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_wof_to_cur_arg_string(char *old_arg, t_flags *flag)
{
	int		len;
	int		between;
	char	*tmp;
	char	*new_arg;

	len = ft_strlen(old_arg);
	if (len < flag->wof)
	{
		between = flag->wof - len;
		tmp = ft_memset(ft_strnew(between), (int)flag->wof_c, between);
		new_arg = ft_strjoin(tmp, old_arg);
		ft_strdel(&tmp);
		ft_strdel(&old_arg);
		return(new_arg);
	}
	return (old_arg);
}

char	*is_there_wof(char *str, t_flags *flag)
{
	char	*wof;
	int		i;

	if (!(wof = ft_strnew(1)))
		return (NULL);
	i = 0;
	while (ft_isdigit(*str))
	{
		wof = ft_realloc(wof, ft_strlen(wof) + 1);
		wof[i++] = *str++;
	}
	flag->wof = ft_atoi(wof);
	ft_strdel(&wof);
	return (str);
}