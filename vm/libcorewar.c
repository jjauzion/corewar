/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcorewar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:16:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/08 13:02:33 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_address(int address)
{
	address = address % MEM_SIZE;
	if (address < 0)
		address = MEM_SIZE - address;
	return (address);
}

int		mem2int(t_uchar *mem, int index, int size)
{
	int		i;
	int		value;
	void	*ptr;

	ptr = (void*)&value;
	i = -1;
	while (++i < size)
		ft_memset(&ptr[size - 1 - i], (int)mem[get_address(index + i)], 1);
	return (value);
}

int		reg2int(t_process *process, int reg)
{
	int		value;
	char	*ptr;
	int		i;

	value = 0;
	ptr = (char*)&value;
	i = (REG_SIZE > 4) ? 3 : REG_SIZE - 1;
	while (i >= 0)
	{
		*ptr = process->reg[reg][i];
		ptr++;
		i--;
	}
	return (value);
}

void	int2reg(t_process *process, int reg, int value)
{
	int		i;
	char	*ptr;

	ptr = (char*)&value;
	i = (REG_SIZE > 4) ? 3 : REG_SIZE - 1;
	while (i >= 0)
	{
		process->reg[reg][i] = *ptr;
		ptr++;
		i--;
	}
}

int		arg2int(t_process *process, int arg_id, t_uchar *mem, int arg_index)
{
	int		address;
	int		reg;
	int		value;

	if (process->op->arg_type[arg_id] == T_IND)
	{
		address = (short)mem2int(mem, arg_index, (int)S_SHORT) % IDX_MOD;
		value = mem2int(mem, process->pc + address, REG_SIZE); //REG_SIZE tjr?
	}
	else if (process->op->arg_type[arg_id] == T_DIR)
		value = mem2int(mem, arg_index, ft_min(DIR_SIZE, REG_SIZE));
	else if (process->op->arg_type[arg_id] == T_REG)
	{
		reg = (int)mem[get_address(arg_index)];
		value = reg2int(process, reg);
	}
	else
		value = -1;
	return (value);
}
