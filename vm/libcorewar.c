/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcorewar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:16:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/06 14:27:05 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		mem2int(char *mem)
{
	int		i;
	int		size_int;
	int		value;
	void	*ptr;

	size_int = sizeof(int);
	ptr = (void*)&value;
	i = -1;
	while (++i < size_int)
		ft_memset(&ptr[size_int - 1 - i], (int)mem[i], 1);
	return (value);
}
