/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <smortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:38:35 by smortier          #+#    #+#             */
/*   Updated: 2018/06/11 19:21:12 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_instr(t_params *params)
{
	t_lexer		*file;
	int 		index;

	index = 0;
	file = params->lexer;
	while (file)
	{
		//ft_printf("-- %s\n", file->line);
		if (!str_is_empty(file->line))
			analyze_line(params, file->line, index);
		file = file->next;
		index ++;
	}
	// while (params->instr)
	// {
	// 	ft_printf("OPCODE : [%d], OCP : [%d]\n", params->instr->opcode, params->instr->ocp);
	// 	params->instr = params->instr->next;
	// }
}
