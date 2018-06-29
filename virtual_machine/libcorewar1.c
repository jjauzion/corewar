/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcorewar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:16:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/20 16:13:13 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	change_carry(t_process *process, int value)
{
	if (value == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

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
