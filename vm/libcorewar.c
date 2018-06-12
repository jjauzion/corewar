/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcorewar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:16:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/12 18:21:45 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_address(int address)
{
	address = address % MEM_SIZE;
	if (address < 0)
		address = MEM_SIZE + address;
	return (address);
}

t_uint	mem2int(t_uchar *mem, int index, int size)
{
	int		i;
	t_uint	value;
	void	*ptr;

	ptr = (void*)&value;
	size = (size > 4) ? 4 : size;
	i = -1;
	while (++i < size)
		ft_memset(&ptr[size - 1 - i], (int)mem[get_address(index + i)], 1);
	return (value);
}

void	int2mem(t_uchar *mem, int index, int value)
{
	int		i;
	char	*ptr;

	ptr = (char*)&value;
	i = -1;
	while (++i < 4)
		ft_memset(&mem[get_address(index + i)], (int)*(ptr + 3 - i), 1);
}

int		reg2int(t_process *process, t_uint reg)
{
	int		value;
	char	*ptr;
	int		i;

	if (reg <= 0 || reg >= REG_NUMBER)
		return (ERROR);
	value = 0;
	ptr = (char*)&value;
	i = (REG_SIZE > 4) ? 3 : REG_SIZE - 1;
	while (i >= 0)
	{
		*ptr = process->reg[reg - 1][i];
		ptr++;
		i--;
	}
	return (value);
}

int		int2reg(t_process *process, t_uint reg, int value)
{
	int		i;
	char	*ptr;

	if (reg <= 0 || reg >= REG_NUMBER)
		return (ERROR);
	ptr = (char*)&value;
	i = (REG_SIZE > 4) ? 3 : REG_SIZE - 1;
	while (i >= 0)
	{
		process->reg[reg - 1][i] = *ptr;
		ptr++;
		i--;
	}
	return (SUCCESS);
}

int		get_arg_id(t_process *process, int arg_id, t_uchar *mem, int arg_index)
{
	int					id;

	if (process->op->arg_type[arg_id] == T_IND)
		id = (short)mem2int(mem, arg_index, (int)S_SHORT);
	else if (process->op->arg_type[arg_id] == T_DIR && process->op->dir_size == 2)
		id = (short)mem2int(mem, arg_index, process->op->dir_size);
	else if (process->op->arg_type[arg_id] == T_DIR)
		id = (int)mem2int(mem, arg_index, process->op->dir_size);
	else if (process->op->arg_type[arg_id] == T_REG)
		id = (int)mem[get_address(arg_index)];
	else
		id = -1;
	return (id);
}

int		get_arg_val(t_process *process, int arg_id, t_uchar *mem, int arg_index)
{
	t_uint		address;
	t_uint		reg;
	int			value;


	value = -1;
	if (process->op->arg_type[arg_id] == T_IND)
	{
		address = (unsigned short)mem2int(mem, arg_index, (int)S_SHORT) % IDX_MOD;
		value = mem2int(mem, process->pc + address, REG_SIZE); //REG_SIZE tjr?
	}
	else if (process->op->arg_type[arg_id] == T_DIR && process->op->dir_size == 2)
		value = (short)mem2int(mem, arg_index, process->op->dir_size);
	else if (process->op->arg_type[arg_id] == T_DIR)
		value = (int)mem2int(mem, arg_index, process->op->dir_size);
	else if (process->op->arg_type[arg_id] == T_REG)
	{
		reg = mem[get_address(arg_index)];
		value = reg2int(process, reg);
	}
	return (value);
}
