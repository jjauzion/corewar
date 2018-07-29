/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:17:50 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 14:15:25 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_instr	*new_instr(void)
{
	t_instr *new_instr;

	if (!(new_instr = (t_instr *)ft_memalloc(sizeof(t_instr))))
		exit(0);
	return (new_instr);
}

t_instr	*create_instr(t_params *params)
{
	t_instr		*tmp;
	t_instr		*save;

	if (params->instr == NULL)
	{
		tmp = new_instr();
		return (tmp);
	}
	else
	{
		tmp = params->instr;
		save = tmp;
		if (!tmp)
		{
			ft_printf("Wrong file, please check instructions ...\n");
			exit(0);
		}
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_instr();
		return (save);
	}
}

void	init_instr(t_params *params)
{
	params->instr = create_instr(params);
}

void	print(t_params *params)
{
	t_instr	*tmp;
	int		index;

	ft_printf("\n\e[100mDumping annotated program on standard output\n");
	ft_printf("Program size : %d bytes\n", params->header.prog_size);
	ft_printf("Name : '%s'\n", params->header.prog_name);
	ft_printf("Comment : '%s'\e[0m\n\n", params->header.comment);
	tmp = params->instr;
	while (tmp)
	{
		index = -1;
		ft_printf("\e[44mOpcode : [%d]\e[0m\t", tmp->opcode);
		ft_printf("\e[7mAddress(%d)\e[0m\t", tmp->address);
		ft_printf("\e[41mBytes(%d)\e[0m\n", tmp->nbr_bytes);
		ft_printf("\t\tOCP : %d\n", tmp->ocp);
		while (++index < tmp->nbr_arg)
		{
			ft_printf("arg[%d] : %s\t--->\t", index, tmp->arg[index]);
			ft_printf("val[%d] : %d\n", index, tmp->arg_value[index]);
		}
		ft_printf("--------------------------------------------------------\n");
		tmp = tmp->next;
	}
}
