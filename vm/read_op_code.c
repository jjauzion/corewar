/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_op_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:50:53 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/19 16:00:24 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_op			*read_op_code(t_arena *arena, t_process *process)
{
	int		i;
	int		op_code;
	t_op	*op;

	op_code = (int)arena->mem[get_address(process->pc)];
	i = -1;
	while (op_tab[++i].op_code != op_code && op_tab[i].name)
	{}
	if (op_tab[i].name == NULL)
	{
		process->pc = get_address(process->pc + 1);
		return (NULL);
	}
	if (!(op = (t_op*)ft_memalloc(sizeof(t_op))))
		return (error_ptr(NULL, "error op malloc\n"));
	op->op_code = op_code;
	op->nb_cycle = op_tab[i].nb_cycle;
	process->exe_cycle = arena->last_check + arena->cycle + op->nb_cycle - 1;
	op->name = ft_strdup(op_tab[i].name);
	op->nb_arg = op_tab[i].nb_arg;
	return (op);
}
