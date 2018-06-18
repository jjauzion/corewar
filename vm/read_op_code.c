/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_op_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:50:53 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/18 19:46:46 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_op			*read_op_code(t_arena *arena, t_process *process)
{
	int		op_code;
	int		op_index;
	t_op	*op;

	op_code = (int)arena->mem[get_address(process->pc)];
	if ((op_index = get_op_index(op_code)) < 0)
	{
		process->pc = get_address(process->pc + 1);
		remove_from_schedule(arena, process->pid, arena->last_check + arena->cycle);
		add2schedule(arena, process, arena->last_check + arena->cycle + 1);
		return (NULL);
	}
	if (!(op = (t_op*)ft_memalloc(sizeof(t_op))))
		return (error_ptr(NULL, "error op malloc\n"));
	op->op_code = op_code;
	op->nb_cycle = op_tab[op_index].nb_cycle;
	//process->exe_cycle = arena->last_check + arena->cycle + op->nb_cycle;
	op->name = op_tab[op_index].name;
	op->nb_arg = op_tab[op_index].nb_arg;
	remove_from_schedule(arena, process->pid, arena->last_check + arena->cycle);
	if (arena->cycle + arena->last_check == 0)
		add2schedule(arena, process, arena->last_check + arena->cycle + op->nb_cycle);
	else
		add2schedule(arena, process, arena->last_check + arena->cycle + op->nb_cycle - 1);
	return (op);
}
