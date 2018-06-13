/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:40:39 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/13 15:33:12 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		and(t_process *process, t_arena *arena)
{
	int			arg[3];
	int			arg_size;
	int			result;

	arg[0] = get_arg_val(process, 0, arena->mem, process->pc + 2);
	if (process->op->arg_type[0] == T_REG)
		arg_size = 1;
	else
		arg_size = (process->op->arg_type[0] == T_IND) ? 2 : 4;
	arg[1] = get_arg_val(process, 1, arena->mem, process->pc + 2 + arg_size);
	if (process->op->arg_type[1] == T_REG)
		arg_size += 1;
	else
		arg_size += (process->op->arg_type[1] == T_IND) ? 2 : 4;
	arg[2] = get_arg_id(process, 2, arena->mem, process->pc + 2 + arg_size);
	result = arg[0] & arg[1];
	int2reg(process, arg[2], result);
	change_carry(process, result);
	show_operation(arena, process, arg, NULL);
	return (SUCCESS);
}
