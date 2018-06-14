/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:12:51 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/14 20:31:35 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void printbits_int(unsigned int v, int fd)
{
	int tmp[4];
	unsigned char to_print;

	tmp[0] = v >> 24;
	tmp[1] = v >> 16 & 0xFF;
	tmp[2] = v >> 8 & 0xFF;
	tmp[3] = v & 0xFF;
	to_print = tmp[0];
	write(fd, &to_print, 1);
	to_print = tmp[1];
	write(fd, &to_print, 1);
	to_print = tmp[2];
	write(fd, &to_print, 1);
	to_print = tmp[3];
	write(fd, &to_print, 1);
	// ft_printf("%d %d %d %d\n", tmp[0], tmp[1], tmp[2], tmp[3]);
}

void printbits_short(unsigned int v, int fd)
{
	int tmp[4];
	unsigned char to_print;

	tmp[0] = v >> 24;
	tmp[1] = v >> 16 & 0xFF;
	tmp[2] = v >> 8 & 0xFF;
	tmp[3] = v & 0xFF;
	to_print = tmp[2];
	write(fd, &to_print, 1);
	to_print = tmp[3];
	write(fd, &to_print, 1);
	// ft_printf("%d %d\n", tmp[3], tmp[2]);
}

void	write_bytecode(t_params *params)
{
	int	file;
	t_instr *tmp;
	int index;
	unsigned char to_print;

	tmp = params->instr;
	file = open("test.cor", O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	print_header(file, params);
	while (tmp)
	{
		index  = 0;
		to_print = tmp->opcode;
		write(file, &to_print, 1);
		if (tmp->ocp)
		{
			to_print = tmp->ocp;
			write(file, &to_print, 1);
		}
		while (index < tmp->nbr_arg)
		{
			to_print = (unsigned char)tmp->arg_value[index];
			tmp->arg_type[index] == REG_CODE ? write(file, &to_print, REG_BYTES) : 0;
			tmp->arg_type[index] == IND_CODE ? printbits_short(tmp->arg_value[index], file) : 0;
			if (tmp->arg_type[index] == DIR_CODE)
			{
				if (tmp->d2 == 1)
					printbits_short(tmp->arg_value[index], file);
				else
					printbits_int(tmp->arg_value[index], file);
			}
			index += 1;
		}
		tmp = tmp->next;
	}
	close(file);
}
//
// void 	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }
