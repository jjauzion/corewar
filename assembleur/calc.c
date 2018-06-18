/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:34:38 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/18 20:11:24 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		calc_label_value(t_params *params, t_instr *tmp, int index)
{
	int		address;
	t_label	*tmp2;

	address = 0;
	tmp2 = params->label;
	while (tmp2)
	{
		if (ft_strcmp(tmp2->name, tmp->arg[index] + 2) == 0 &&
			ft_strlen(tmp2->name) == ft_strlen(tmp->arg[index] + 2))
			return (tmp2->value - tmp->address);
		tmp2 = tmp2->next;
	}
	return (0);
}

int		calc_label_value_ind(t_params *params, t_instr *tmp, int index)
{
	int		address;
	t_label	*tmp2;

	address = 0;
	tmp2 = params->label;
	while (tmp2)
	{
		if (ft_strcmp(tmp2->name, tmp->arg[index] + 1) == 0 &&
			ft_strlen(tmp2->name) == ft_strlen(tmp->arg[index] + 1))
			return (tmp2->value - tmp->address);
		tmp2 = tmp2->next;
	}
	return (0);
}

int		direct_case(t_params *params, t_instr *tmp, int index)
{
	if (ft_strchr(tmp->arg[index], LABEL_CHAR))
		return (calc_label_value(params, tmp, index));
	else
		return (ft_atoi(tmp->arg[index] + 1));
}

int		ind_case(t_params *params, t_instr *tmp, int index)
{
	if (ft_strchr(tmp->arg[index], LABEL_CHAR))
		return (calc_label_value_ind(params, tmp, index));
	else
		return (ft_atoi(tmp->arg[index]));
}

void	fill_arg_values(t_params *params)
{
	t_instr	*tmp;
	int		index;

	tmp = params->instr;
	while (tmp)
	{
		index = -1;
		if (!(tmp->arg_value = (int *)ft_memalloc(sizeof(int) * tmp->nbr_arg)))
			return ;
		while (++index < tmp->nbr_arg)
		{
			if (tmp->arg_type[index] == REG_CODE)
				tmp->arg_value[index] = ft_atoi(tmp->arg[index] + 1);
			else if (tmp->arg_type[index] == DIR_CODE)
				tmp->arg_value[index] = direct_case(params, tmp, index);
			else if (tmp->arg_type[index] == IND_CODE)
				tmp->arg_value[index] = ind_case(params, tmp, index);
		}
		tmp = tmp->next;
	}
}
