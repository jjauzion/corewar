/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:25:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/14 14:25:44 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		verbose(t_arena *arena, t_process *current_process, int step, int dump)
{
	if (step == 10 && opt_is_set(arena->option->option, 'v'))
	{
		ft_printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		ft_printf("cycle = %d ; nb_process = %d ; ",
				arena->last_check + arena->cycle, arena->nb_process);
		ft_printf("cycle to die = %d ; last check = %d ; nb lives = %d\n"
				, arena->cycle2die, arena->last_check, arena->nb_live);
	}
	else if (step == 20 && opt_is_set(arena->option->option, 'v'))
		ft_printf("champions %d has live %d times since last check\n",
				arena->champions[dump]->id, arena->champions[dump]->nb_live);
	else if (step == 30 && opt_is_set(arena->option->option, 'v'))
		ft_printf("process %d has been killed\n", current_process->pid);
	else if (step == 40 && opt_is_set(arena->option->option, 'v'))
	{
		ft_printf("--------------\nprocess %d:\n", current_process->pid);
		ft_printf("reg[0] = %d ; pc = %d ; carry = %d\n",
				reg2int(current_process, 1), current_process->pc, current_process->carry);
	}
	else if (step == 45 && opt_is_set(arena->option->option, 'v'))
	{
		ft_printf("op = (null)\n");
		print_arena(arena->mem, current_process->pc, 1);
	}
	else if (step == 50 && opt_is_set(arena->option->option, 'v'))
	{
		ft_printf("op_code = %d not executed\n", current_process->op->op_code);
		print_arena(arena->mem, current_process->pc, current_process->op_size);
	}
	else if (step == 60 && opt_is_set(arena->option->option, 'v'))
	{
		ft_printf("op_code = %d executed\n", current_process->op->op_code);
		print_arena(arena->mem, current_process->pc, current_process->op_size);
	}
	else if (step == 70 && opt_is_set(arena->option->option, 'v'))
	{
		ft_printf("op_code = %d ; exe cycle = %d\n", current_process->op->op_code, current_process->exe_cycle);
		print_arena(arena->mem, current_process->pc, current_process->op_size);
	}
	else if (step == 80 && opt_is_set(arena->option->option, 'v'))
		ft_printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	else if (step == 90 && opt_is_set(arena->option->option, 'v'))
		ft_printf("FINAL cycle = %d ; nb_process = %d\n", arena->last_check + arena->cycle, arena->nb_process);
}

void		show_cycle(t_arena *arena, t_process *current_process, int step, int dump)
{
	static int	last_cycle2die = CYCLE_TO_DIE;

	(void)current_process;
	(void)dump;
	if (step == 10 && opt_is_set(arena->option->option, 'c') && arena->cycle + arena->last_check != 0)
		ft_printf("It is now cycle %d\n", arena->cycle + arena->last_check);
	if (step == 85 && opt_is_set(arena->option->option, 'c') && arena->cycle2die != last_cycle2die)
	{
		last_cycle2die = arena->cycle2die;
		ft_printf("Cycle to die is now %d\n", arena->cycle2die);
	}
}

int			print_dump_mem(t_arena *arena)
{
	if (opt_is_set(arena->option->option, 'd') &&
			arena->cycle + arena->last_check == arena->option->d_cycle)
	{
		print_arena(arena->mem, 0, MEM_SIZE);
		return (1);
	}
	return (0);
}

void		show_pc_mouvement(t_arena *arena, t_process *current_process, int step, int dump)
{
	int		i;
	(void)current_process;
	(void)dump;
	if (step == 51 && opt_is_set(arena->option->option, 'p') && current_process->op_size)
	{
		ft_printf("ADV %d (0x%04x -> 0x%04x) ", current_process->op_size,
				current_process->pc, current_process->pc + current_process->op_size);
		i = current_process->pc - 1;
		while (++i < current_process->pc + current_process->op_size)
			ft_printf("%02x ", arena->mem[get_address(i)]);
		ft_printf("\n");
	}
}

void		show_operation(t_arena *arena, t_process *current_process, int arg[3], char *msg)
{
	int		i;

	(void)msg;
	if (!opt_is_set(arena->option->option, 'o'))
		return ;
	ft_printf("P% 5d | %s ", current_process->pid, current_process->op->name);
	i = -1;
	while (++i < current_process->op->nb_arg)
	{
		if (current_process->op->arg_type[i] == T_REG && i == current_process->op->nb_arg - 1)
			ft_printf("r%d", arg[i]);
		else
			ft_printf("%d", arg[i]);
		if (i + 1 < current_process->op->nb_arg)
			ft_printf(" ");
	}
	ft_printf("\n");
/*	if (msg != NULL)
		ft_printf("       | -> %s %d + %d = %d (with pc and mod %d)\n", msg,
				arg[0], arg[1], arg[0] + arg[1], get_address(current_process->pc + (int)address));*/
}
