/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:16:42 by ppoinot           #+#    #+#             */
/*   Updated: 2016/11/10 09:06:26 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include "../libft/libft.h"

char		*lire_un_fichier(int fd);
int			nb_de_ligne(char **tab);

/*typedef struct		s_objet
{
		char		*buff_1;
		char		**tab;
		int			n;
}					t_try;
*/
#endif
