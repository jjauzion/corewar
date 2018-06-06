/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:29:32 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/06 18:06:46 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		exec_process(t_process *process, t_arena *arena)
{
	process->pc += process->op_size;
	free(process->op);
	process->op_size = 0;
	process->op = read_op(arena, process);
	printf("process->op : %p\n", process->op);
	return (0);
}
