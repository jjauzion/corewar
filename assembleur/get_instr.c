/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <smortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:38:35 by smortier          #+#    #+#             */
/*   Updated: 2018/06/21 16:26:54 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	fill_address(t_params *params)
{
	t_instr	*tmp;
	int		address;

	address = 0;
	tmp = params->instr;
	while (tmp)
	{
		tmp->address = address;
		address += tmp->nbr_bytes;
		tmp = tmp->next;
	}
}

void	get_instr(t_params *params)
{
	t_lexer	*file;
	int		index;

	index = 0;
	file = params->lexer;
	while (file)
	{
		if (!str_is_empty(file->line))
			analyze_line(params, file->line, index);
		file = file->next;
		index += 1;
	}
	get_label_instr(params);
	fill_address(params);
	fill_arg_values(params);
}
