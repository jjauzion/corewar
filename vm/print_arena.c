/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 17:05:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/23 15:09:10 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		print_arena(t_arena *arena, size_t index, size_t length)
{
	size_t			i;

	i = index;
	while (i < index + length)
	{
		if (i % 64 == 0 && i > index)
			ft_printf("\n");
		if (i % 64 == 0 && !opt_is_set(arena->option->option, 'v'))
			ft_printf("0x%04x : ", i);
		ft_printf("%02x ", arena->mem[get_address(i)]);
		i++;
	}
	ft_printf("\n");
}
