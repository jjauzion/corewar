/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:05:31 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/04 17:23:28 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		write_champions(t_arena *arena, t_champion **champions)
{
	int i;

	i = 0;
	while (i < arena->nb_champion)
	{
		ft_memcpy(&arena->mem[i * MEM_SIZE / arena->nb_champion], champions[i]->code,
				champions[i]->header.prog_size);
		i++;
	}
	return (SUCCESS);
}
