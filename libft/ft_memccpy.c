/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:31:11 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/16 11:45:47 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	target;

	target = (unsigned char)c;
	c_dst = dst;
	while (n)
	{
		*c_dst = *(const char*)src;
		c_dst++;
		if (*(const unsigned char*)src == target)
			return (c_dst);
		src++;
		n--;
	}
	return (NULL);
}
