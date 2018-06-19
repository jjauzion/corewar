/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:05:31 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/19 16:50:59 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		init_arena(t_arena *arena, t_champion **champions)
{
	int			i;
	int			address;
	t_process	*new_process;

	arena->champions = champions;
	arena->cycle2die = CYCLE_TO_DIE;
	i = 0;
	while (i < arena->nb_champion)
	{
		address = i * MEM_SIZE / arena->nb_champion;
		arena->champions[i]->id = -i - 1;
		new_process = create_process(address, arena->champions[i]->id, NULL);
		arena->nb_process++;
		new_process->next = arena->process;
		arena->process = new_process;
		ft_memcpy(&arena->mem[address], champions[i]->code,
				champions[i]->header.prog_size);
		new_process->op = read_op_code(arena, new_process);
		new_process->exe_cycle++;
		i++;
	}
	return (SUCCESS);
}
