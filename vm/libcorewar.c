/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcorewar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:16:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/07 17:29:48 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		mem2int(char *mem, int size)
{
	int		i;
	int		value;
	void	*ptr;

	ptr = (void*)&value;
	i = -1;
	while (++i < size)
		ft_memset(&ptr[size - 1 - i], (int)mem[i], 1);
	return (value);
}

int		get_address(int address)
{
	address = address % MEM_SIZE;
	if (address < 0)
		address = MEM_SIZE - address;
	return (address);
}
