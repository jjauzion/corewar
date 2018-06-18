/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:28:15 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/18 17:58:00 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	calc_bytes_and(t_instr *tmp)
{
	int 	index;

	tmp->nbr_bytes = 1;
	index = -1;
	ft_printf("SIZE 1: \e[32m[%d]\e[0m\n", tmp->nbr_bytes);
	while (++index < tmp->nbr_arg)
	{
		ft_printf("TYPE: \e[31m[%d]\e[0m\n", tmp->arg_type[index]);
			tmp->arg_type[index] == REG_CODE ? tmp->nbr_bytes += REG_BYTES : 0;
			tmp->arg_type[index] == DIR_CODE ? tmp->nbr_bytes += DIR_BYTES : 0;
			tmp->arg_type[index] == IND_CODE ? tmp->nbr_bytes += IND_BYTES : 0;
			ft_printf("SIZE 2: \e[32m[%d]\e[0m\n", tmp->nbr_bytes);
	}
	if (tmp->ocp != 0)
		tmp->nbr_bytes += 1;
	ft_printf("SIZE 3: \e[32m[%d]\e[0m\n", tmp->nbr_bytes);
}

void	save_and(t_params *params, int id, char *line)
{
	t_instr *tmp;

	init_instr(params);
	tmp = params->instr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->id = id;
	tmp->opcode = 6;
	tmp->nbr_arg = 3;
	tmp->d2 = 0;
	get_params(tmp, line);
	fill_arg_types(params, tmp);
	calc_ocp(tmp);
	calc_bytes_and(tmp);
	ft_printf("1: [%s], 2: [%s] 3: [%s]\n", tmp->arg[0], tmp->arg[1], tmp->arg[2]);
	ft_printf("1: [%d], 2: [%d] 3: [%d]\n", tmp->arg_type[0], tmp->arg_type[1], tmp->arg_type[2]);
	ft_printf("OCP: %d\n", tmp->ocp);
	ft_printf("Bytes: %d\n\n", tmp->nbr_bytes);
}
