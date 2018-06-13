/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:18:10 by tmerli            #+#    #+#             */
/*   Updated: 2018/06/13 15:43:25 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		add(t_process *process, t_arena *arena)
{
	int arg[3];

	arg[0] = get_arg_val(process, 0, arena->mem, process->pc + 1);
	arg[1] = get_arg_val(process, 1, arena->mem, process->pc + 2);
	arg[2] = get_arg_id(process, 2, arena->mem, process->pc + 3);
	change_carry(process, arg[0] + arg[1]);
	int2reg(process, arg[0] + arg[1], arg[2]);
	arg[0] = get_arg_id(process, 0, arena->mem, process->pc + 1);
	arg[1] = get_arg_id(process, 1, arena->mem, process->pc + 2);
	if (opt_is_set(arena->option->option, 'o'));
		ft_prinf("P% 5d | %s r%d r%d r%d\n", process->pid, process->op->name,
				arg[0], arg[1], arg[2]);
}

int		sub(t_process *process, t_arena *arena)
{
	int arg[3];

	arg[0] = get_arg_val(process, 0, arena->mem, process->pc + 1);
	arg[1] = get_arg_val(process, 1, arena->mem, process->pc + 2);
	arg[2] = get_arg_id(process, 2, arena->mem, process->pc + 3);
	change_carry(process, arg[0] - arg[1]);
	int2reg(process, arg[0] - arg[1], arg[2]);
	arg[0] = get_arg_id(process, 0, arena->mem, process->pc + 1);
	arg[1] = get_arg_id(process, 1, arena->mem, process->pc + 2);
	if (opt_is_set(arena->option->option, 'o'));
		ft_prinf("P% 5d | %s r%d r%d r%d\n", process->pid, process->op->name,
				arg[0], arg[1], arg[2]);
}
