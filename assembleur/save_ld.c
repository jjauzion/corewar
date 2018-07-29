/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 19:06:58 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 14:18:52 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	save_ld(t_params *params, int id, char *line)
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
	tmp->opcode = 2;
	tmp->nbr_arg = 2;
	tmp->d2 = 0;
	get_params(tmp, line);
	fill_arg_types(params, tmp);
	calc_ocp(tmp);
	calc_bytes(tmp);
}
