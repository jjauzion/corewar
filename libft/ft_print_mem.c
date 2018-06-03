/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:02:58 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/28 12:04:14 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_mem(void *adr, size_t length)
{
	unsigned char	*byte_array;
	size_t			i;

	byte_array = adr;
	i = 0;
	while (i < length)
	{
		if (i % 2 == 0)
			ft_printf(" ");
		ft_printf("%02X", (unsigned)byte_array[i]);
		i++;
	}
}
