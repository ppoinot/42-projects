/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:00:42 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/14 09:44:03 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_gnl
{
	char		*stce;
	char		*buff;
	int			nb;
}					t_gnl;

int					get_next_line(const int fd, char **line);
char				*ft_swapping(char *stce, int i);
char				*ft_copy(t_gnl **gnl, char *line);
char				*transf(char *stce, char *buff);
int					initial(t_gnl **gnl);

#endif
