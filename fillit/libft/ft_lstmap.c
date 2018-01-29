/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 17:51:03 by vcharles          #+#    #+#             */
/*   Updated: 2016/01/03 13:04:15 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*run;

	if (!lst)
		return (NULL);
	ptr = NULL;
	if (!(ptr = f(lst)))
		return (NULL);
	run = ptr;
	run->next = NULL;
	while (lst->next)
	{
		lst = lst->next;
		run->next = f(lst);
		if (run->next == NULL)
			return (NULL);
		run = run->next;
	}
	return (ptr);
}
