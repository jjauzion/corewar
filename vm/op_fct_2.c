/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 12:01:46 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/09 15:02:07 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		st(t_process *process, t_arena *arena)
{
	int				value;
	int				address;

	value = get_arg_val(process, 0, arena->mem, process->pc + 2);
	address = get_arg_id(process, 1, arena->mem, process->pc + 3);
	if (process->op->arg_type[1] == T_REG)
		int2reg(process, address, value);
	else
		int2mem(arena->mem, (address % IDX_MOD) + process->pc, value);
	if (value == 0)
		process->carry = 1;
	else
		process->carry = 0;
	return (SUCCESS);
}
