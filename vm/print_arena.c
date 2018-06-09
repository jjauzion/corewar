/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 17:05:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/09 17:17:38 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		print_arena(t_uchar *mem, size_t index, size_t length)
{
	size_t			i;
	size_t			ligne;

	i = index;
	ligne = 0;
	while (i < index + length)
	{
		if (i % 64 == 0 && i > index)
			ft_printf("\n");
		if (i % 64 == 0)
		{
			if (i == index)
				ft_printf("0x%04x : ", ligne);
			else
				ft_printf("%#06x : ", ligne);
			ligne += 64;
		}
		ft_printf("%02x ", mem[get_address(i)]);
		i++;
	}
	ft_printf("\n");
}
