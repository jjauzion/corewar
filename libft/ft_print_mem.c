/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:02:58 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/09 15:50:51 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_mem(void *adr, size_t length)
{
	unsigned char	*byte_array;
	size_t			i;
	int				ligne;

	byte_array = adr;
	i = 0;
	ligne = 0;
	while (i < length)
	{
		if (i % 64 == 0 && i > 0)
			ft_printf("\n");
		if (i % 64 == 0)
		{
			if (i == 0)
				ft_printf("0x%04x : ", ligne);
			else
				ft_printf("%#06x : ", ligne);
			ligne += 64;
		}
		ft_printf("%02X ", (unsigned)byte_array[i]);
		i++;
	}
	ft_printf("\n");
}
