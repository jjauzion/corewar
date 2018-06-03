/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:53:02 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/16 14:11:34 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;

	if (src >= dst)
	{
		c_dst = (unsigned char *)dst;
		while (len--)
		{
			*c_dst = *(const char *)src;
			src++;
			c_dst++;
		}
	}
	else
	{
		c_dst = (unsigned char *)dst + len - 1;
		src = src + len - 1;
		while (len--)
		{
			*c_dst = *(const char *)src;
			src--;
			c_dst--;
		}
	}
	return (dst);
}
