/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:17:09 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/16 14:44:25 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	target;
	unsigned char	*ptr;

	target = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == target)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
