/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:00:42 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/12 14:24:43 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int					get_next_line(const int fd, char **line);
char				*lire_un_fd(int fd);

typedef struct		s_gnl
{
	char		*stce;
	char		*buff;
	int			nb;
}					t_gnl;

#endif
