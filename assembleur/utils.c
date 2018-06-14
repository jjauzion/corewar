/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:17:50 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/14 20:37:34 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_instr	*new_instr(void)
{
	t_instr *new_instr;

	if (!(new_instr = (t_instr *)ft_memalloc(sizeof(t_instr))))
		return (NULL);
	return (new_instr);
}

t_instr	*create_instr(t_params *params)
{
	t_instr		*tmp;
	t_instr		*save;

	if (params->instr == NULL)
	{
		tmp = new_instr();
		return (tmp);
	}
	else
	{
		tmp = params->instr;
		save = tmp;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_instr();
		return (save);
	}
}

void	init_instr(t_params *params)
{
	params->instr = create_instr(params);
}
