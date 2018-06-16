/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:40:39 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/16 15:57:22 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ld(t_process *process, t_arena *arena)
{
	int			arg[3];
	int			arg_size;

	arg[0] = get_arg_val(process, 0, arena->mem, process->pc + 2);
	arg_size = (process->op->arg_type[0] == T_IND) ? IND_SIZE : DIR_SIZE;
	arg[1] = get_arg_id(process, 1, arena->mem, process->pc + 2 + arg_size);
	int2reg(process, (t_uint)arg[1], arg[0]);
	show_operation(arena, process, arg, NULL);
	change_carry(process, arg[0]);
	return (SUCCESS);
}

int		lld(t_process *process, t_arena *arena)
{
	int			arg[3];
	int			arg_size;

	process->op_idx_mod = 0;
	arg[0] = get_arg_val(process, 0, arena->mem, process->pc + 2);
	process->op_idx_mod = 1;
	arg[0] = (process->op->arg_type[0] == T_IND) ? (arg[0] >> 16) : arg[0];
	arg_size = (process->op->arg_type[0] == T_IND) ? IND_SIZE : DIR_SIZE;
	arg[1] = get_arg_id(process, 1, arena->mem, process->pc + 2 + arg_size);
	int2reg(process, (t_uint)arg[1], arg[0]);
	show_operation(arena, process, arg, NULL);
	change_carry(process, arg[0]);
	return (SUCCESS);
}

int		lldi(t_process *process, t_arena *arena)
{
	int			arg[3];
	int			arg_size;
	int			address;
	t_uint		value;

	arg[0] = get_arg_val(process, 0, arena->mem, process->pc + 2);
	arg_size = (process->op->arg_type[0] == T_REG) ? 1 : 2;
	arg[1] = get_arg_val(process, 1, arena->mem, process->pc + 2 + arg_size);
	address = arg[1] + arg[0];
	arg_size += (process->op->arg_type[1] == T_REG) ? 1 : 2;
	arg[2] = (t_uint)get_arg_id(process, 2, arena->mem, process->pc + 2 +
			arg_size);
	value = mem2int(arena->mem, process->pc + (int)address, REG_SIZE);
	int2reg(process, arg[2], value);
	if (opt_is_set(arena->option->option, 'o'))
	{
		ft_printf("P% 5d | %s %d %d r%d\n",
				process->pid, process->op->name, arg[0], arg[1], arg[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
				arg[0], arg[1], arg[0] + arg[1], address + process->pc);
	}
	change_carry(process, address); //address a tester
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
	arg[2] = (t_uint)get_arg_id(process, 2, arena->mem, process->pc + 2 +
			arg_size);
	value = mem2int(arena->mem, process->pc + (int)address, REG_SIZE);
	int2reg(process, arg[2], value);
	if (opt_is_set(arena->option->option, 'o'))
	{
		ft_printf("P% 5d | %s %d %d r%d\n",
				process->pid, process->op->name, arg[0], arg[1], arg[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
				arg[0], arg[1], arg[0] + arg[1], get_address(address + process->pc));
	}
	return (SUCCESS);
}
