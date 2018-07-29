/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:50:00 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 14:18:52 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	save_fork(t_params *params, int id, char *line)
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
	tmp->opcode = 12;
	tmp->nbr_arg = 1;
	tmp->ocp = 0;
	get_params(tmp, line);
	fill_arg_types(params, tmp);
	calc_bytes(tmp);
	tmp->d2 = 1;
	tmp->nbr_bytes -= 2;
}
