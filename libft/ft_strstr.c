/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:32:50 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/10 19:44:25 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;
	const char	*scan;

	if (*needle == '\0')
		return ((char*)haystack);
	h = haystack;
	while (*h)
	{
		scan = h;
		n = needle;
		while (*scan == *n)
		{
			n++;
			scan++;
			if (!*n)
				return ((char *)h);
		}
		h++;
	}
	return (NULL);
}
