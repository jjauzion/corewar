/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 12:01:46 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/20 18:07:54 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			st(t_process *process, t_arena *arena)
{
	int				arg[3];
	int				tmp;

	arg[0] = get_arg_val(process, 0, arena->mem, process->pc + 2);
	arg[1] = get_arg_id(process, 1, arena->mem, process->pc + 3);
	tmp = get_arg_id(process, 0, arena->mem, process->pc + 2);
	if (process->op->arg_type[1] == T_REG)
		int2reg(process, arg[1], arg[0]);
	else
		int2mem(arena->mem, (arg[1] % IDX_MOD) + process->pc, arg[0]);
	arg[0] = tmp;
	if (opt_is_set(arena->option->option, 'o'))
		ft_printf("P% 5d | %s r%d %d\n", process->pid, process->op->name,
				arg[0], arg[1]);
	return (SUCCESS);
}

int			sti(t_process *process, t_arena *arena)
{
	int arg[3];
	int position;
	int	tmp;

	arg[0] = get_arg_val(process, 0, arena->mem, process->pc + 2);
	arg[1] = get_arg_val(process, 1, arena->mem, process->pc + 3);
	position = 1;
	if (process->op->arg_type[1] != T_REG)
		position++;
	arg[2] = get_arg_val(process, 2, arena->mem, process->pc + 3 + position);
	tmp = get_arg_id(process, 0, arena->mem, process->pc + 2);
	int2mem(arena->mem, ((arg[1] + arg[2]) % IDX_MOD) + process->pc, arg[0]);
	arg[0] = tmp;
	if (opt_is_set(arena->option->option, 'o'))
	{
		ft_printf("P% 5d | %s r%d %d %d\n",
				process->pid, process->op->name, arg[0], arg[1], arg[2]);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
				arg[1], arg[2], arg[1] + arg[2],
				(arg[1] + arg[2]) % IDX_MOD + process->pc);
	}
	return (SUCCESS);
}

int			live(t_process *process, t_arena *arena)
{
	int		i;
	int		arg[3];

	arg[0] = get_arg_val(process, 0, arena->mem, process->pc + 1);
	process->last_live_cycle = arena->cycle + arena->last_check;
	arena->nb_live++;
	show_operation(arena, process, arg, NULL);
	i = -1;
	while (++i < arena->nb_champion)
	{
		if (arg[0] == arena->champions[i]->id)
		{
			if (opt_is_set(arena->option->option, 'l'))
				ft_printf("Player %d (%s) is said to be alive\n", i + 1,
						arena->champions[i]->header.prog_name);
			arena->champions[i]->last_live_cycle =
				arena->last_check + arena->cycle;
			arena->champions[i]->nb_live++;
		}
	}
	return (SUCCESS);
}

int			zjmp(t_process *process, t_arena *arena)
{
	short	value;

	process->op->arg_type[0] = T_DIR;
	value = get_arg_val(process, 0, arena->mem, process->pc + 1);
	if (process->carry == 1)
	{
		if (opt_is_set(arena->option->option, 'o'))
			ft_printf("P% 5d | zjmp %d OK\n", process->pid, value);
		process->op_size = 0;
		process->pc = get_address(process->pc + (value % IDX_MOD));
	}
	else if (opt_is_set(arena->option->option, 'o'))
		ft_printf("P% 5d | zjmp %d FAILED\n", process->pid, value);
	return (SUCCESS);
}
