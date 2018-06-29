/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:38:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/28 15:33:42 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_uint	get_pid(void)
{
	static t_uint	pid = 0;

	if (pid >= PID_MAX)
		pid = 1;
	else
		pid++;
	return (pid);
}

t_process		*create_process(int address, int id, t_process *origin_process)
{
	t_process		*new_process;
	int				i;

	if (!(new_process = (t_process*)ft_memalloc(sizeof(t_process))))
		return (error_ptr(NULL, "new process malloc error"));
	new_process->op_idx_mod = 1;
	new_process->pc = address;
	new_process->pid = get_pid();
	if (origin_process != NULL)
	{
		i = -1;
		while (++i < REG_NUMBER)
			ft_memcpy(new_process->reg[i], origin_process->reg[i], REG_SIZE);
		new_process->carry = origin_process->carry;
		new_process->last_live_cycle = origin_process->last_live_cycle;
	}
	else
		int2reg(new_process, 1, id);
	new_process->next = NULL;
	return (new_process);
}
