/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:25:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/20 15:58:30 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	show_cycle(t_arena *arena, t_process *current_process, int step,
		int dump)
{
	static int	last_cycle2die = CYCLE_TO_DIE;

	(void)current_process;
	(void)dump;
	if (step == 10 && opt_is_set(arena->option->option, 'c') &&
			arena->cycle + arena->last_check != 0)
		ft_printf("It is now cycle %d\n", arena->cycle + arena->last_check);
	if (step == 85 && opt_is_set(arena->option->option, 'c') &&
			arena->cycle2die != last_cycle2die)
	{
		last_cycle2die = arena->cycle2die;
		ft_printf("Cycle to die is now %d\n", arena->cycle2die);
	}
}

int		print_dump_mem(t_arena *arena)
{
	if (opt_is_set(arena->option->option, 'd') &&
			arena->cycle + arena->last_check == arena->option->d_cycle)
	{
		print_arena(arena->mem, 0, MEM_SIZE);
		return (1);
	}
	return (0);
}

void	show_pc_mouvement(t_arena *arena, t_process *current_process,
		int step, int dump)
{
	int		i;

	(void)current_process;
	(void)dump;
	if (step == 51 && opt_is_set(arena->option->option, 'p') &&
			current_process->op_size)
	{
		ft_printf("ADV %d (0x%04x -> 0x%04x) ", current_process->op_size,
				current_process->pc,
				current_process->pc + current_process->op_size);
		i = current_process->pc - 1;
		while (++i < current_process->pc + current_process->op_size)
			ft_printf("%02x ", arena->mem[get_address(i)]);
		ft_printf("\n");
	}
}

void	show_operation(t_arena *arena, t_process *current_process, int arg[3],
		char *msg)
{
	int		i;

	(void)msg;
	if (!opt_is_set(arena->option->option, 'o'))
		return ;
	ft_printf("P% 5d | %s ", current_process->pid, current_process->op->name);
	i = -1;
	while (++i < current_process->op->nb_arg)
	{
		if (current_process->op->arg_type[i] == T_REG &&
				i == current_process->op->nb_arg - 1)
			ft_printf("r%d", arg[i]);
		else
			ft_printf("%d", arg[i]);
		if (i + 1 < current_process->op->nb_arg)
			ft_printf(" ");
	}
	ft_printf("\n");
}
