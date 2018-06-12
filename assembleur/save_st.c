/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 19:07:50 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/11 19:17:45 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	save_st(t_params *params, int id, char *line)
{
	t_instr *tmp;

	init_instr(params);
	tmp = params->instr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->id = id;
	tmp->opcode = 3;
	tmp->nbr_arg = 2;
	get_params(tmp, line);
	fill_arg_types(params, tmp);
	calc_ocp(tmp);
	ft_printf("\n1: [%s], 2: [%s]\n\n", tmp->arg[0], tmp->arg[1]);
	ft_printf("\n1: [%d], 2: [%d]\n\n", tmp->arg_type[0], tmp->arg_type[1]);
	ft_printf("OCP: %d\n\n", tmp->ocp);
}