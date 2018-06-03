/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:29:01 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/13 17:31:01 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(wchar_t const *s1)
{
	size_t	len;
	size_t	i;
	wchar_t	*s_cpy;

	len = ft_wstrlen(s1);
	if (!(s_cpy = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		s_cpy[i] = s1[i];
		i++;
	}
	s_cpy[i] = '\0';
	return (s_cpy);
}
