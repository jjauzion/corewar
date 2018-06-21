/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:28:15 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 14:18:52 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	calc_bytes_and(t_instr *tmp)
{
	int	index;

	tmp->nbr_bytes = 1;
	index = -1;
	while (++index < tmp->nbr_arg)
	{
		tmp->arg_type[index] == REG_CODE ? tmp->nbr_bytes += REG_BYTES : 0;
		tmp->arg_type[index] == DIR_CODE ? tmp->nbr_bytes += DIR_BYTES : 0;
		tmp->arg_type[index] == IND_CODE ? tmp->nbr_bytes += IND_BYTES : 0;
	}
	if (tmp->ocp != 0)
		tmp->nbr_bytes += 1;
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
}
