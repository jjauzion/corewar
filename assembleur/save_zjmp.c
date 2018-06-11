/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:45:02 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/11 19:33:14 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	save_zjmp(t_params *params, int id, char *line)
{
	t_instr *tmp;

	init_instr(params);
	tmp = params->instr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->id = id;
	tmp->opcode = 9;
	tmp->nbr_arg = 1;
	tmp->ocp = 0;
	get_params(tmp, line);
	fill_arg_types(params, tmp);
	ft_printf("\n1: [%s]\n\n", tmp->arg[0]);
	ft_printf("\n1: [%d]\n\n", tmp->arg_type[0]);
	ft_printf("OCP: %d\n\n", tmp->ocp);
}
