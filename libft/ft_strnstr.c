/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:47:12 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/10 20:29:57 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*n;
	const char	*scan;
	size_t		i;
	size_t		j;

	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	while (*haystack && ++i <= len)
	{
		scan = haystack;
		n = needle;
		j = i;
		while (*scan == *n && j <= len)
		{
			n++;
			scan++;
			j++;
			if (!*n)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
