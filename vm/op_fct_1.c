/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:40:39 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/08 18:47:36 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ld(t_process *process, t_arena *arena)
{
	t_uint		reg;
	int			arg;
	int			arg_size;

	arg = get_arg_val(process, 0, arena->mem, process->pc + 2);
	arg_size = (process->op->arg_type[0] == T_IND) ? IND_SIZE : DIR_SIZE;
	reg = (t_uint)get_arg_id(process, 1, arena->mem, process->pc + 2 + arg_size);
	int2reg(process, reg, arg);
	if (arg == 0)
		process->carry = 1;
	else
		process->carry = 0;
	return (SUCCESS);
}

int		ldi(t_process *process, t_arena *arena)
{
	int			arg[3];
	int			arg_size;
	int			address;
	t_uint		value;

	arg[0] = get_arg_val(process, 0, arena->mem, process->pc + 2);
	arg_size = (process->op->arg_type[0] == T_REG) ? 1 : 2;
	arg[1] = get_arg_val(process, 1, arena->mem, process->pc + 2 + arg_size);
	address = (arg[1] + arg[0]) % IDX_MOD;
	arg_size += (process->op->arg_type[1] == T_REG) ? 1 : 2;
	arg[2] = (t_uint)get_arg_id(process, 2, arena->mem, process->pc + 2 + arg_size);
	value = mem2int(arena->mem, process->pc + (int)address, REG_SIZE);
	int2reg(process, arg[2], value);
	if (value == 0)
		process->carry = 1;
	else
		process->carry = 0;
	return (SUCCESS);
}
