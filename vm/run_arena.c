/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_arena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:12:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/06 18:19:19 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_process	*kill_process(t_arena *arena, t_process *last_process, t_process *tokill)
{
	if (arena->process == tokill)
	{
		arena->process = tokill->next;
		free(tokill); //free_process() ???
		return (arena->process);
	}
	last_process->next = tokill->next;
	free(tokill);
	return (last_process->next);
}

int					run_arena(t_arena *arena)
{
	t_process	*current_process;
	t_process	*last_process;

	current_process = arena->process;
	arena->cycle = 0;
	arena->cycle2die = CYCLE_TO_DIE;
	arena->last_check = 0;
	while (arena->process)
	{
printf("cycle = %d ; nb_process = %d\n", arena->last_check + arena->cycle, arena->nb_process);
		if (arena->cycle == CYCLE_TO_DIE)
		{
			arena->last_check += arena->cycle;
			arena->cycle = 0;
			current_process = arena->process;
			last_process = NULL;
			while (current_process)
			{
				if (current_process->last_live_cycle == 0)
				{
					current_process = kill_process(arena, last_process, current_process);
					arena->nb_process--;
				}
				else
				{
					last_process = current_process;
					current_process = current_process->next;
				}
			}
			if (arena->nb_live >= NBR_LIVE || arena->nb_check > MAX_CHECKS)
			{
				arena->cycle2die -= CYCLE_DELTA;
				arena->nb_check = 0;
			}
			arena->nb_live = 0;
		}
		current_process = arena->process;
		while (current_process)
		{
printf("process[%d].pc = %d\n", (int)current_process->reg[0][3], current_process->pc);
			if (current_process->op == NULL)
			{
				if (!(current_process->op = read_op(arena, current_process)))
					current_process->pc++;
			}
			else if (arena->cycle + arena->last_check == current_process->exe_cycle)
				exec_process(current_process, arena);
			current_process = current_process->next;
		}
		arena->cycle++;
	}
printf("FINAL cycle = %d ; nb_process = %d\n", arena->last_check + arena->cycle, arena->nb_process);
	return (SUCCESS);
}
