/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_arena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:12:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/18 19:26:37 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_process	*kill_process(t_arena *arena, int cycle, t_process *last_process, t_process *tokill)
{
	verbose(arena, tokill, 30, 0);
	if (last_process == NULL)
	{
		arena->schedule[cycle] = tokill->next;
		free_process(tokill);
		arena->nb_process--;
		return (arena->schedule[cycle]);
	}
	last_process->next = tokill->next;
	free_process(tokill);
	arena->nb_process--;
	return (last_process->next);
}

int					run_arena(t_arena *arena)
{
	t_process	*current_process;
	t_process	*tmp;
	int			i;

	arena->cycle = 0;
	arena->cycle2die = CYCLE_TO_DIE;
	arena->last_check = 0;
	while (arena->nb_process && arena->cycle2die > 0)
	{
		verbose(arena, current_process, 10, 0);
		show_cycle(arena, current_process, 10, 0);
		current_process = arena->schedule[(arena->last_check + arena->cycle) % CYCLE_TO_DIE];
		while (current_process)
		{
			tmp = current_process->next;
			verbose(arena, current_process, 40, 0);
			if (current_process->op != NULL)
			{
				verbose(arena, current_process, 70, 0);
				exec_op(current_process, arena);
			}
			else
				current_process->op = read_op_code(arena, current_process);
/*			if (arena->cycle == arena->cycle2die || arena->cycle2die <= 0)
			{
				if (current_process->last_live_cycle == 0)
				{
					current_process = kill_process(arena, last_process, current_process);
					arena->nb_process--;
				}
				else
				{
					current_process->last_live_cycle = 0;
					last_process = current_process;
					current_process = current_process->next;
				}
			}
			else*/
			current_process = tmp;
		}
		if (arena->cycle == arena->cycle2die || arena->cycle2die <= 0)
		{
			arena->nb_check++;
			arena->last_check += arena->cycle;
			arena->cycle = 0;
			i = -1;
			while (++i < CYCLE_TO_DIE)
			{
				current_process = arena->schedule[i];
				tmp = NULL;
				while (current_process)
				{
					if (current_process->last_live_cycle == 0)
					{
						remove_from_schedule(arena, current_process->pid, i);
						current_process = kill_process(arena, i, tmp, current_process);
					}
					else
					{
						current_process->last_live_cycle = 0;
						tmp = current_process;
						current_process = current_process->next;
					}
				}
			}
			i = -1;
			while (++i < arena->nb_champion)
				arena->champions[i]->nb_live = 0;
			if (arena->nb_live >= NBR_LIVE || arena->nb_check >= MAX_CHECKS)
			{
				arena->cycle2die -= CYCLE_DELTA;
				arena->nb_check = 0;
			}
			arena->nb_live = 0;
		}
		verbose(arena, current_process, 80, 0);
		if (print_dump_mem(arena))
			return (ERROR);
		arena->cycle++;
		show_cycle(arena, current_process, 85, 0);
	}
	//free arena...
	verbose(arena, current_process, 90, 0);
	return (SUCCESS);
}
