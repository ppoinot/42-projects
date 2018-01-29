/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:29:56 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/19 16:18:36 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../libft/libft.h"

typedef	struct			s_tetris
{
	char				**shape;
	int					s_y;
	int					s_x;
	char				pos;
	struct s_tetris		*bridge_p;
	int					c_y;
	int					c_x;
	struct s_tetris		*next;
	struct s_tetris		*prev;
}						t_tetris;

/*
** BACKTRACKING.C
*/
void					ft_move_right(t_tetris *tetris, int size);
void					ft_erase_tetris(char **map, t_tetris *tetris);
void					ft_write_tetris(char **map, t_tetris *tetris);
int						ft_try_slot(char **map, int size, t_tetris *tetris);
char					**backtracking(t_tetris *tetris, char **map, int size);

/*
** CHECK.C
*/
int						check_tetris_content(char *str);
int						check_tetris_format(char *str);

/*
** INIT.C
*/
int						make_tetriminos(t_tetris **tetris, char *sample);
int						create_tetris_struct(t_tetris **tetris);
int						read_file(int fd, t_tetris **tetris);
int						main(int argc, char **argv);

/*
** BRIDGE.C
*/
int						shapecmp(t_tetris *buff, t_tetris *tetris);
t_tetris				*set_bridge_p(t_tetris *tetris);
t_tetris				*use_bridge_p(t_tetris *tetris, int size);

/*
** SOLVE.C
*/
void					cleanup(t_tetris **tetris);
void					print_map(char **map, int size);
void					solve(t_tetris **tetris, int size);

/*
** STRUCT.C
*/
char					**make_grid(int size_y, int size_x);
void					free_grid(char **map, int size_y);
void					ft_trim_is_life(t_tetris *tetris, char **buff);
int						ft_trim_tetris(t_tetris *tetris);
int						ft_greaterroot(int nb_tetris);

#endif
