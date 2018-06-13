/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:29:32 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/13 17:21:13 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "fct_op.c"

int			exec_op(t_process *process, t_arena *arena)
{
	int		i;

	if (process->exe_op == 1)
	{
		i = -1;
		while (g_op_fct_tab[++i].op_code != process->op->op_code && g_op_fct_tab[i].op_code != 0)
		{}
		if (g_op_fct_tab[i].op_code == 0)
		{
			process->pc = get_address(process->pc + process->op_size);
			//error_ptr(process->op, "op code not found in g_op_fct_tab\n"); 
			ft_printf("op code %d not found in g_op_fct_tab\n", process->op->op_code); 
			process->op = read_op(arena, process);
			return(ERROR); 
		}
		g_op_fct_tab[i].fct(process, arena);
		verbose(arena, process, 60, 0);
	}
	else
		verbose(arena, process, 50, 0);
	show_pc_mouvement(arena, process, 51, 0);
	process->pc = get_address(process->pc + process->op_size);
	free(process->op);
	process->op_size = 0;
	process->op = read_op(arena, process);
	return (SUCCESS);
}
