/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedule.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:30:09 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/18 19:26:09 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			remove_from_schedule(t_arena *arena, t_uint pid, int cycle)
{
	t_process	*process1;
	
	cycle = cycle % CYCLE_TO_DIE;
	process1 = arena->schedule[cycle];
	if (process1 && process1->pid == pid)
	{
		arena->schedule[cycle] = process1->next;
		return (SUCCESS);
	}
	while (process1->next)
	{

		if (process1->next->pid == pid)
		{
			process1->next = process1->next->next;
			return (SUCCESS);
		}
		process1 = process1->next;
	}
	return (error_int("pid not found, process can't be removed from schedule\n"));
}

int			add2schedule(t_arena *arena, t_process *process2add, int cycle)
{
	t_process	*process1;

	cycle = cycle % CYCLE_TO_DIE;
	process1 = arena->schedule[cycle];
	if (process1 == NULL || process1->pid < process2add->pid)
	{
		arena->schedule[cycle] = process2add;
		process2add->next = process1;
		return (SUCCESS);
	}
	while (process1->next && process2add->pid < process1->next->pid)
		process1 = process1->next;
	process2add->next = process1->next;
	process1->next = process2add;
	return (SUCCESS);
}
