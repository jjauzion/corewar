/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:12:51 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 17:05:08 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	printbits_int(unsigned int v, int fd)
{
	int				tmp[4];
	unsigned char	to_print;

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
}

void	printbits_short(unsigned int v, int fd)
{
	int				tmp[4];
	unsigned char	to_print;

	tmp[0] = v >> 24;
	tmp[1] = v >> 16 & 0xFF;
	tmp[2] = v >> 8 & 0xFF;
	tmp[3] = v & 0xFF;
	to_print = tmp[2];
	write(fd, &to_print, 1);
	to_print = tmp[3];
	write(fd, &to_print, 1);
}

void	print_ocp(int file, int ocp)
{
	unsigned char	to_print;

	to_print = ocp;
	write(file, &to_print, 1);
}

void	print_body(int file, t_instr *tmp)
{
	int				index;
	unsigned char	to_print;

	while (tmp)
	{
		index = 0;
		to_print = tmp->opcode;
		write(file, &to_print, 1);
		tmp->ocp ? print_ocp(file, tmp->ocp) : 0;
		while (index < tmp->nbr_arg)
		{
			to_print = (unsigned char)tmp->arg_value[index];
			if (tmp->arg_type[index] == REG_CODE)
				write(file, &to_print, REG_BYTES);
			if (tmp->arg_type[index] == IND_CODE)
				printbits_short((short)tmp->arg_value[index], file);
			if (tmp->arg_type[index] == DIR_CODE)
			{
				tmp->d2 ? printbits_short(tmp->arg_value[index], file) :
							printbits_int(tmp->arg_value[index], file);
			}
			index += 1;
		}
		tmp = tmp->next;
	}
}

void	write_bytecode(t_params *params)
{
	int		file;
	t_instr	*tmp;
	char	*name;

	name = ft_strjoin(params->file_name, ".cor");
	tmp = params->instr;
	file = open(name, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	ft_strdel(&name);
	print_header(file, params);
	print_body(file, tmp);
	close(file);
}
