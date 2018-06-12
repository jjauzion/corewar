/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:31:50 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/10 18:46:40 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void check_label_name(t_params *params, char *name)
{
	int		ok;
	t_label *tmp;

	ok = 0;
	tmp = params->label;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, name, ft_str_ws_len(name)))
		{
			if (ft_strlen(tmp->name) == ft_strlen(name))
				ok = 1;
		}
		tmp = tmp->next;
	}
	if (ok != 1)
	{
		ft_printf("Error: This label does not exist : %s\n", name);
		exit(0);
	}
}

static	void check_nbr_arg_live(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
		;
	if (i != 1)
	{
		ft_printf("Error:\n");
		exit (0);
	}
}

int	check_live_par(t_params *params, char *line, int index_line)
{
	char	**split;
	char	*arg1;
	int		index;

	split = ft_strsplit(line, SEPARATOR_CHAR);
	check_nbr_arg_live(split);
	arg1 = ft_strtrim(split[0]);
	index = -1;
	while (split[++index])
		ft_strdel(&split[index]);
	ft_memdel((void *)&split);
	if (check_type(params, arg1) != DIR_CODE)
	{
		ft_printf("Error : Wrong type of arg1 on instr %d (live)\n", index_line);
		exit(0);
	}
	ft_strdel(&arg1);
	return (1);
}
