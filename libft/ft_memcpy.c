/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:31:57 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/16 11:56:19 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c_dst;

	c_dst = (unsigned char *)dst;
	while (n)
	{
		*c_dst = *(const char *)src;
		src++;
		c_dst++;
		n--;
	}
	return (dst);
}
