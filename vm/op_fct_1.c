/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:40:39 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/08 13:10:29 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ld(t_process *process, t_arena *arena)
{
	int			reg;
	int			arg;

	arg = arg2int(process, 0, arena->mem, process->pc + 2);
	if (process->op->arg_type[0] == T_IND)
		reg = (int)arena->mem[get_address(process->pc + 2 + IND_SIZE)] - 1;
	else
		reg = (int)arena->mem[get_address(process->pc + 2 + DIR_SIZE)] - 1;
	int2reg(process, reg, arg);
	return (SUCCESS);
/*
	short		address;
	int			i;

	if (process->op->arg_type[0] == T_IND)
	{
		address = (short)mem2int(arena->mem, get_address(process->pc + 2), (int)S_SHORT) % IDX_MOD;
		reg = (int)arena->mem[get_address(process->pc + 2 + IND_SIZE)] - 1;
		i = -1;
		while (++i < REG_SIZE)
			process->reg[reg][i] = arena->mem[get_address(process->pc + address + i)];
	}
	if (process->op->arg_type[0] == T_DIR)
	{
		reg = (int)arena->mem[get_address(process->pc + 2 + DIR_SIZE)] - 1;
		i = (REG_SIZE > DIR_SIZE) ? DIR_SIZE : REG_SIZE;
		while (--i >= 0)
			process->reg[reg][i] = arena->mem[get_address(process->pc +  2 + i)];
	}
	return (SUCCESS);
*/
}

/*
int		ldi(t_process *process, t_arena *arena)
{
	if (process->op->arg_type[0] == T_IND)
	{

	}
}
*/
