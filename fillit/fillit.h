/:q************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:29:56 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/04 22:03:44 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>

# define BUFF_SIZE 21

typedef	struct			s_tetris
{
	char				**shape;
	int					size_y;
	int					size_x;
	char				pos;
	struct s_tetris		*next;
	struct s_tetris		*prev;
}						t_tetris;

typedef struct			s_map
{
	char				**grid;
	int					size;
}						t_map;

int						ft_greaterroot(int nb_tetris);
void					solve(t_tetris *tetris, int nb_tetris);

#endif
