/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:16:42 by vcharles          #+#    #+#             */
/*   Updated: 2016/03/13 02:38:28 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include "./libft/libft.h"

typedef	struct			s_gnl
{
	int					line;
	char				*sentence;
	int					fd;
	struct s_gnl		*next;
}						t_gnl;

/*
** BACKTRACKING.C
*/

#endif
