/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_lld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:54:27 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/18 15:59:57 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	save_lld(t_params *params, int id, char *line)
{
	t_instr *tmp;

	init_instr(params);
	tmp = params->instr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->id = id;
	tmp->opcode = 13;
	tmp->nbr_arg = 2;
	tmp->d2 = 0;
	get_params(tmp, line);
	fill_arg_types(params, tmp);
	calc_ocp(tmp);
	calc_bytes(tmp);
	// ft_printf("1: [%s], 2: [%s]\n", tmp->arg[0], tmp->arg[1]);
	// ft_printf("1: [%d], 2: [%d]\n", tmp->arg_type[0], tmp->arg_type[1]);
	// ft_printf("OCP: %d\n", tmp->ocp);
	// ft_printf("Bytes: %d\n\n", tmp->nbr_bytes);
}
