/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 19:02:48 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/11 19:15:41 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	save_aff(t_params *params, int id, char *line)
{
	t_instr *tmp;

	init_instr(params);
	tmp = params->instr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->id = id;
	tmp->opcode = 16;
	tmp->nbr_arg = 1;
	get_params(tmp, line);
	fill_arg_types(params, tmp);
	calc_ocp(tmp);
	ft_printf("\n1: [%s]\n\n", tmp->arg[0]);
	ft_printf("\n1: [%d]\n\n", tmp->arg_type[0]);
	ft_printf("OCP: %d\n\n", tmp->ocp);
}
