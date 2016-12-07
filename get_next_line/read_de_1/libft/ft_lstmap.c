/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 03:34:19 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/11 03:38:43 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = NULL;
	start = NULL;
	while (lst)
	{
		new = f(ft_lstnew(lst->content, lst->content_size));
		if (!start)
			start = new;
		tmp = ft_lstpush(&tmp, new);
		lst = lst->next;
	}
	return (start);
}
