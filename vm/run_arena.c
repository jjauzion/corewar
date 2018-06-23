/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_arena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:12:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/23 11:49:16 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_process	*kill_process(t_arena *arena, t_process *last_process,
		t_process *tokill)
{
	show_death(arena, tokill);
	if (arena->process == tokill)
	{
		arena->process = tokill->next;
		free(tokill->op);
		free(tokill);
		arena->nb_process--;
		return (arena->process);
	}
	last_process->next = tokill->next;
	free(tokill->op);
	free(tokill);
	arena->nb_process--;
	return (last_process->next);
}

static void			check_cycle2die(t_arena *arena)
{
	t_process	*process;
	t_process	*last_process;

	if (arena->cycle == arena->cycle2die || arena->cycle2die <= 0)
	{
		process = arena->process;
		last_process = NULL;
		while (process)
		{
			if (process->last_live_cycle <= arena->last_check)
				process = kill_process(arena, last_process, process);
			else
			{
				last_process = process;
				process = process->next;
			}
		}
	}
}

static void			exe_process(t_arena *arena)
{
	t_process	*process;

	process = arena->process;
	while (process)
	{
		if (process->op == NULL)
			process->op = read_op_code(arena, process);
		else if (arena->cycle + arena->last_check == process->exe_cycle)
			exec_op(process, arena);
		display(arena, process, 0);
		process = process->next;
	}
	check_cycle2die(arena);
}

static void			update_arena(t_arena *arena)
{
	int			i;
	t_process	*process;

	if (arena->cycle == arena->cycle2die || arena->cycle2die <= 0)
	{
		arena->nb_check++;
		arena->last_check += arena->cycle;
		arena->cycle = 0;
		process = arena->process;
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
}

int					run_arena(t_arena *arena)
{
	while (arena->process)
	{
		show_cycle(arena, NULL, 10, 0);
		exe_process(arena);
		update_arena(arena);
		display(arena, NULL, 100);
		if (print_dump_mem(arena))
			return (ERROR);
		arena->cycle++;
		show_cycle(arena, NULL, 85, 0);
	}
	return (SUCCESS);
}
