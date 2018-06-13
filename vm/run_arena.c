/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_arena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:12:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/13 15:01:59 by jjauzion         ###   ########.fr       */
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
	int			i;

	current_process = arena->process;
	arena->cycle = 0;
	arena->cycle2die = CYCLE_TO_DIE;
	arena->last_check = 0;
	while (arena->process)
	{
		verbose(arena, current_process, 10, 0);
		show_cycle(arena, current_process, 10, 0);
		if (arena->cycle == arena->cycle2die || arena->cycle2die <= 0)
		{
			arena->nb_check++;
			arena->last_check += arena->cycle;
			arena->cycle = 0;
			current_process = arena->process;
			last_process = NULL;
			i = -1;
			while (++i < arena->nb_champion)
			{
				verbose(arena, current_process, 20, i);
				arena->champions[i]->nb_live = 0;
			}
			while (current_process)
			{
				if (current_process->last_live_cycle == 0)
				{
					verbose(arena, current_process, 30, 0);
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
			if (arena->nb_live >= NBR_LIVE || arena->nb_check >= MAX_CHECKS)
			{
				arena->cycle2die -= CYCLE_DELTA;
				arena->nb_check = 0;
			}
			arena->nb_live = 0;
		}
		current_process = arena->process;
		while (current_process)
		{
			verbose(arena, current_process, 40, 0);
			if (current_process->op == NULL)
			{
				verbose(arena, current_process, 45, 0);
				current_process->op = read_op(arena, current_process);
			}
			else if (arena->cycle + arena->last_check == current_process->exe_cycle)
				exec_op(current_process, arena);
			else
				verbose(arena, current_process, 70, 0);
			current_process = current_process->next;
		}
		verbose(arena, current_process, 80, 0);
		if (opt_is_set(arena->option->option, 'd')
				&& arena->cycle + arena->last_check == arena->option->d_cycle)
		{
			print_arena(arena->mem, 0, MEM_SIZE);
			return (SUCCESS);
		}
		arena->cycle++;
		show_cycle(arena, current_process, 85, 0);
	}
	verbose(arena, current_process, 90, 0);
	return (SUCCESS);
}
