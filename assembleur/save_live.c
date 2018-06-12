/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 19:04:47 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/12 15:45:09 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	save_live(t_params *params, int id, char *line)
{
	t_instr *tmp;

	init_instr(params);
	tmp = params->instr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->id = id;
	tmp->opcode = 1;
	tmp->nbr_arg = 1;
	tmp->ocp = 0;
	get_params(tmp, line);
	fill_arg_types(params, tmp);
	calc_bytes(tmp);
	ft_printf("1: [%s]\n", tmp->arg[0]);
	ft_printf("1: [%d]\n", tmp->arg_type[0]);
	ft_printf("OCP: %d\n", tmp->ocp);
ft_printf("Bytes: %d\n\n", tmp->nbr_bytes);
}
