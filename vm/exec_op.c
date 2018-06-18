/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:29:32 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/18 19:55:21 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "fct_op.c"

int			exec_op(t_process *process, t_arena *arena)
{
	int		op_index;

	read_op(arena, process);
	if (process->exe_op == 1)
	{
		if ((op_index = get_op_index(process->op->op_code)) < 0)
			return (error_int("op code not found in op_tab\n")); 
		g_op_fct_tab[op_index].fct(process, arena);
		verbose(arena, process, 60, 0);
	}
	show_pc_mouvement(arena, process, 51, 0);
	process->pc = get_address(process->pc + process->op_size);
	free(process->op);
	process->op_size = 0;
	process->op = NULL;
	remove_from_schedule(arena, process->pid, arena->last_check + arena->cycle);
	add2schedule(arena, process, arena->last_check + arena->cycle + 1);
	return (SUCCESS);
}
