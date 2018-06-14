/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:43:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/14 18:19:44 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		fork_op(t_process *process, t_arena *arena)
{
	int			arg;
	t_process	*new_process;
	int			reg1;

	arg = get_arg_val(process, 0, arena->mem, process->pc + 1);
	reg1 = reg2int(process, 1);
	if (!(new_process = create_process(get_address(process->pc + (arg % IDX_MOD)), reg1, process)))
		return (ERROR);
	new_process->op = read_op_code(arena, new_process);
	arena->nb_process++;
	new_process->next = arena->process;
	arena->process = new_process;
	if (opt_is_set(arena->option->option, 'o'))
		ft_printf("P% 5d | %s %d (%d)\n",
				process->pid, process->op->name, arg, process->pc + (arg % IDX_MOD));
	return (SUCCESS);
}

int		lfork_op(t_process *process, t_arena *arena)
{
	int			arg;
	t_process	*new_process;
	int			reg1;

	arg = get_arg_val(process, 0, arena->mem, process->pc + 1);
	reg1 = reg2int(process, 1);
	if (!(new_process = create_process(get_address(process->pc + arg), reg1, process)))
		return (ERROR);
	new_process->op = read_op_code(arena, new_process);
	arena->nb_process++;
	new_process->next = arena->process;
	arena->process = new_process;
	if (opt_is_set(arena->option->option, 'o'))
		ft_printf("P% 5d | %s %d (%d)\n",
				process->pid, process->op->name, arg, process->pc + arg);
	return (SUCCESS);
}

int		aff(t_process *process, t_arena *arena)
{
	int arg;

	arg = get_arg_val(process, 0, arena->mem, process->pc + 2);
	if (opt_is_set(arena->option->option, 'a'))
		ft_printf("Aff: %c\n", (char)arg);
	return (SUCCESS);
}
