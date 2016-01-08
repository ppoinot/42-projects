/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:29:56 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/08 18:43:26 by vcharles         ###   ########.fr       */
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
	int					s_y;
	int					s_x;
	char				pos;
	int					c_y;
	int					c_x;
	struct s_tetris		*next;
	struct s_tetris		*prev;
}						t_tetris;

/*
 * BUILD.C
 */
char					**make_grid(int size_y, int size_x);
void					free_grid(char **map, int size_y);
void					ft_trim_is_life(t_tetris *tetris, char **buff);
int						ft_trim_tetris(t_tetris *tetris);
int						ft_greaterroot(int nb_tetris);

/*
 * CHECK.C
 */
int						check_tetris_content(char *str);
int						check_tetris_format(char *str);
int						make_tetris(t_tetris *tetris, char *sample);
int						read_file(int fd, t_tetris *tetris);
int						main(int argc, char **argv);

/*
 * SOLVE.C
 */
void					ft_erase_tetris(char **map, int size, t_tetris *tetris);
void					ft_write_tetris(char **map, t_tetris *tetris);
int						ft_try_slot(char **map, int size, t_tetris *tetris);
char					**solve(t_tetris *save, int size);

#endif
