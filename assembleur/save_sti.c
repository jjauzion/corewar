/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:48:29 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 14:19:26 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	save_sti(t_params *params, int id, char *line)
{
	t_instr *tmp;

	init_instr(params);
	tmp = params->instr;
	if (!tmp)
	{
		ft_printf("Wrong file, please check instructions ...\n");
		exit(0);
	}
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
}
