/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:48:29 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/18 15:59:57 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	save_sti(t_params *params, int id, char *line)
{
	t_instr *tmp;

	init_instr(params);
	tmp = params->instr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->id = id;
	tmp->opcode = 11;
	tmp->nbr_arg = 3;
	get_params(tmp, line);
	fill_arg_types(params, tmp);
	calc_ocp(tmp);
	calc_bytes(tmp);
	tmp->arg_type[1] == DIR_CODE ? tmp->nbr_bytes -= 2 : 0;
	tmp->arg_type[2] == DIR_CODE ? tmp->nbr_bytes -= 2 : 0;
	tmp->d2 = 1;
	// ft_printf("1: [%s], 2: [%s] 3: [%s]\n", tmp->arg[0], tmp->arg[1], tmp->arg[2]);
	// ft_printf("1: [%d], 2: [%d] 3: [%d]\n", tmp->arg_type[0], tmp->arg_type[1], tmp->arg_type[2]);
	// ft_printf("OCP: %d\n", tmp->ocp);
	// ft_printf("Bytes: %d\n\n", tmp->nbr_bytes);
}
