/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 11:41:41 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/28 15:24:40 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		print_cycle(t_arena *arena)
{
	int		i;

	ft_printf("cycle = %d\n", arena->cycle + arena->last_check);
	ft_printf("cycle_to_die = %d\n", arena->cycle2die);
	ft_printf("nb of processes = %d\n", arena->nb_process);
	i = -1;
	while (++i < arena->nb_champion)
	{
		ft_printf("champion %d has lived %d\n",
				i, arena->champions[i]->nb_live);
		ft_printf("champion %d last live cycle\n", i);
	}
	ft_printf("Arena_memory :\n");
	print_arena(arena, 0, MEM_SIZE);
	ft_printf("--------------------------------------------------------\n");
}

int				display(t_arena *arena, t_process *process, int step)
{
	int		i;

	if (!opt_is_set(arena->option->option, 'v'))
		return (0);
	if (step == 0)
	{
		ft_printf("Arena size : %d\n", MEM_SIZE);
		ft_printf("NB of player : %d\n", arena->nb_champion);
		i = -1;
		while (++i < arena->nb_champion)
			ft_printf("Player %d name : %s\nPlayer %d comment : %s\n",
					i, arena->champions[i]->header.prog_name,
					i, arena->champions[i]->header.comment);
		ft_printf("--------------------------------------------------------\n");
	}
	else if (step == 10)
		ft_printf("process %d, pc position = %d\n", process->pid, process->pc);
	else if (step == 100)
		print_cycle(arena);
	return (1);
}
