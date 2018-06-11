/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 12:01:46 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/11 18:42:37 by jjauzion         ###   ########.fr       */
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
	return (SUCCESS);
}

int		sti(t_process *process, t_arena *arena)
{
	int value;
	int adress;
	int position;

	value  = get_arg_val(process, 0, arena->mem, process->pc + 2);
	adress = get_arg_val(process, 1, arena->mem, process->pc + 3);
	position = 1;
	if (process->op->arg_type[1] != T_REG)
		position++;
	adress += get_arg_val(process, 2, arena->mem, process->pc + 3 + position);
	int2mem(arena->mem, (adress % IDX_MOD) + process->pc, value);
	return (SUCCESS);
}


int		live(t_process *process, t_arena *arena)
{
	int		i;
	int		value;

	process->op->arg_type[0] = T_DIR;
	value = get_arg_val(process, 0, arena->mem, process->pc + 1);
	process->last_live_cycle = arena->cycle;
	arena->nb_live++;
	i = -1;
	while (++i < arena->nb_champion)
	{
		if (value == arena->champions[i]->id)
		{
			arena->champions[i]->last_live_cycle = arena->last_check + arena->cycle;
			arena->champions[i]->nb_live++;
		}
	}
	return (SUCCESS);
}

int		zjmp(t_process *process, t_arena *arena)
{
	short 	value;

	process->op->arg_type[0] = T_DIR;
	value = get_arg_val(process, 0, arena->mem, process->pc + 1);
	if (process->carry == 1)
	{
		process->op_size = 0;
		process->pc = get_address(process->pc + (value % IDX_MOD));
	}
	return (SUCCESS);
}
