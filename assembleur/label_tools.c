/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:16:27 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/19 17:35:12 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label	*get_label_by_pos(t_params *params, int pos)
{
	t_label		*tmp;

	tmp = params->label;
	while (tmp)
	{
		if (pos == tmp->pos)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		get_adress(t_params *params, int id)
{
	int			nb_bytes;
	t_instr		*tmp;

	nb_bytes = 0;
	tmp = params->instr;
	while (tmp)
	{
		if (id == tmp->id)
			return (nb_bytes);
		nb_bytes += tmp->nbr_bytes;
		tmp = tmp->next;
	}
	return (nb_bytes);
}

void	fill_value_label(t_params *params)
{
	t_label		*tmp;

	tmp = params->label;
	while (tmp)
	{
		tmp->value = get_adress(params, tmp->instr);
		// ft_printf("\e[38;5;46mname = [%s]\e[0m, ", tmp->name);
		// ft_printf("\e[38;5;46mvalue = [%d]\e[0m\n", tmp->value);
		tmp = tmp->next;
	}
}

void	get_label_instr(t_params *params)
{
	t_lexer *tmp;
	t_lexer *tmp2;
	int		index;
	int		index2;

	tmp = params->lexer;
	index = 0;
	while (tmp)
	{
		index2 = 0;
		tmp2 = tmp;
		if (get_label_by_pos(params, index))
		{
			while (tmp2 && str_is_empty(tmp2->line))
			{
				index2 += 1;
				tmp2 = tmp2->next;
			}
			if (str_is_empty(tmp->line))
				get_label_by_pos(params, index)->instr = index + index2;
			else
				get_label_by_pos(params, index)->instr = index;
		}
		// ft_printf("\e[38;5;154m FILE = [%s]\e[0m\n", tmp->line);
		tmp = tmp->next;
		index++;
	}
	fill_value_label(params);
}
