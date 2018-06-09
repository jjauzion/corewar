/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_arena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:12:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/09 17:09:26 by jjauzion         ###   ########.fr       */
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
ft_printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
ft_printf("cycle = %d ; nb_process = %d ; ", arena->last_check + arena->cycle, arena->nb_process);
ft_printf("cycle to die = %d ; last check = %d\n", arena->cycle2die, arena->last_check);
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
ft_printf("process %d has been killed\n", current_process->pid);
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
ft_printf("--------------\nprocess %d:\n", current_process->pid);
ft_printf("reg[0] = %d ; pc = %d\n", reg2int(current_process, 1), current_process->pc);
			if (current_process->op == NULL)
			{
ft_printf("op = (null)\n");
print_arena(arena->mem, current_process->pc, 1);
				if (!(current_process->op = read_op(arena, current_process)))
					current_process->pc++;
			}
			else if (arena->cycle + arena->last_check == current_process->exe_cycle)
			{
if (current_process->exe_op == 1)
	ft_printf("op_code = %d executed\n", current_process->op->op_code);
else
	ft_printf("op_code = %d not executed\n", current_process->op->op_code);
print_arena(arena->mem, current_process->pc, current_process->op_size);
				exec_op(current_process, arena);
			}
			else
			{
ft_printf("op_code = %d ; exe cycle = %d\n", current_process->op->op_code, current_process->exe_cycle);
print_arena(arena->mem, current_process->pc, current_process->op_size);
			}
			current_process = current_process->next;
		}
		arena->cycle++;
ft_printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
SPAM3(());
	}
ft_printf("FINAL cycle = %d ; nb_process = %d\n", arena->last_check + arena->cycle, arena->nb_process);
	return (SUCCESS);
}
