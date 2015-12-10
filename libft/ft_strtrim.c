/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 04:56:13 by ppoinot           #+#    #+#             */
/*   Updated: 2015/12/10 04:56:14 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		f;
	int		d;

	f = ft_strlen(s) - 1;
	d = 0;
	if (!s)
		return (NULL);
	while (s[d] == ' ' || s[d] == '\t' || s[d] == '\n')
		d++;
	while (s[f] == ' ' || s[f] == '\t' || s[f] == '\n')
		f--;
	if (f > d)
		return (ft_strsub(s, d, f - d + 1));
	return (ft_strdup(""));
}
