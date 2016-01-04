/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:47:27 by ppoinot           #+#    #+#             */
/*   Updated: 2016/01/04 16:49:05 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 21

#include "libft.h"

int		check_tetris_content(char *str)
{
    int		dieze;
    int		link;
    int		i;
    
    dieze = 0;
    link = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '#')
        {
            dieze++;
            if (str[i + 1] == '#')
                link++;
            if (i < 16 && str[i + 5] == '#')
                link++;
        }
        i++;
    }
    printf("Dieze = %d\n", dieze);
    printf("Link = %d\n", link);
    if(dieze == 4 && link >= 3)
        return (1);
    return (0);
}

int		check_tetris_format(char *str);
{
	int		i;
	int		;

	i = 0
	while (*str)
	{
		if ((i + 1) % 5)
		{
			if (str[i] != '\n)
				return (0);
		}
		else if (i == 20)
		{
			if (str[i] && str[i] != '\n')
				return (0);
		}
		else if (str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	return(check_tetris_content(str));
}

t_list		*add_tetris(int fd)
{
	int			oct_read;
	char		*sample;

	oct_read = read(fd, sample, BUF_SIZE);
	if (oct_read == -1)
		return (NULL);
}

int		main(void)
{
	int		fd;
void
	fd = -1;
	fd = open("sample.fillit", O_RDONLY);
	if (fd != -1)
	{
		char* = add_tetris(fd);
		if (close(fd) == -1)
		{
			ft_putstr("close() error");
			return (0);
		}
		return(1);
	}
	return (0);
}
