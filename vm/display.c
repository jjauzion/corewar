/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 11:41:41 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/23 11:54:13 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	display(t_arena *arena, t_process *process, int step)
{
	if (!opt_is_set(arena->option->option, 'v'))
		return ;
	if (step == 0)
		ft_printf("process %d, pc position = %d\n", process->pid, process->pc);
	else if (step == 100)
	{
		ft_printf("cycle = %d\n", arena->cycle + arena->last_check);
		print_arena(arena->mem, 0, MEM_SIZE);
	}
}
