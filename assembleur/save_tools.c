/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:24:35 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/12 15:26:22 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_params(t_instr *tmp, char *line)
{
	char	**split;
	int		index;

	split = ft_strsplit(line, SEPARATOR_CHAR);
	if (!(tmp->arg = (char **)ft_memalloc(sizeof(char *) * (tmp->nbr_arg + 1))))
		return ;
	tmp->arg[tmp->nbr_arg] = NULL;
	index = -1;
	while (split[++index])
	{
		tmp->arg[index] = ft_strtrim(split[index]);
		ft_strdel(&split[index]);
	}
	ft_memdel((void **)&split);
}

void	calc_bytes(t_instr *tmp)
{
	int 	index;

	tmp->nbr_bytes = 1;
	index = -1;
	while (++index < tmp->nbr_arg)
	{
			tmp->arg_type[index] == REG_CODE ? tmp->nbr_bytes += REG_SIZE : 0;
			tmp->arg_type[index] == DIR_CODE ? tmp->nbr_bytes += DIR_SIZE : 0;
			tmp->arg_type[index] == IND_CODE ? tmp->nbr_bytes += IND_SIZE : 0;
	}
	if (tmp->ocp != 0)
		tmp->nbr_bytes += 1;
}

void	calc_ocp(t_instr *tmp)
{
	int 	index;

	tmp->ocp = 0;
	index = -1;
	while (++index < tmp->nbr_arg)
	{
		if (index == 0)
		{
			tmp->arg_type[index] == REG_CODE ? tmp->ocp += 64 : 0;
			tmp->arg_type[index] == DIR_CODE ? tmp->ocp += 128 : 0;
			tmp->arg_type[index] == IND_CODE ? tmp->ocp += 192 : 0;
		}
		if (index == 1)
		{
			tmp->arg_type[index] == REG_CODE ? tmp->ocp += 16 : 0;
			tmp->arg_type[index] == DIR_CODE ? tmp->ocp += 32 : 0;
			tmp->arg_type[index] == IND_CODE ? tmp->ocp += 48 : 0;
		}
		if (index == 2)
		{
			tmp->arg_type[index] == REG_CODE ? tmp->ocp += 4 : 0;
			tmp->arg_type[index] == DIR_CODE ? tmp->ocp += 8 : 0;
			tmp->arg_type[index] == IND_CODE ? tmp->ocp += 12 : 0;
		}
	}
}

void	fill_arg_types(t_params *params, t_instr *tmp)
{
	int		index;

	index = -1;
	if (!(tmp->arg_type = (int *)ft_memalloc(sizeof(int) * tmp->nbr_arg)))
		return ;
	while (tmp->arg[++index])
		tmp->arg_type[index] = check_type(params, tmp->arg[index]);
}
