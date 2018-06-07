/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:40:39 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/07 18:51:50 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ld(t_process *process, t_arena *arena)
{
	short		address;
	int			i;
	int			reg;

printf("process->op->arg_type[0] = %d\n", process->op->arg_type[0]);
	if (process->op->arg_type[0] == T_IND)
	{
		address = (short)mem2int(&arena->mem[get_address(process->pc + 2)], 2) % IDX_MOD;
		reg = (int)arena->mem[process->pc + 4] - 1;
		i = -1;
		while (++i < REG_SIZE)
			process->reg[reg][i] = arena->mem[get_address(process->pc + address + i)];
	}
	if (process->op->arg_type[0] == T_DIR)
	{
		reg = (int)arena->mem[process->pc + 6] - 1;
printf("reg = %d\n", reg);
		i = (REG_SIZE > DIR_SIZE) ? DIR_SIZE : REG_SIZE;
		while (--i >= 0)
			process->reg[reg][i] = arena->mem[get_address(process->pc + i + 2)];
	}
	return (SUCCESS);
}
