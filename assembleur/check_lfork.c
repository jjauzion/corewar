/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:08:18 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 16:02:42 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_nbr_arg_lfork(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
		;
	if (i != 1)
	{
		ft_printf("Error: Wrong number of arguments!\n");
		exit(0);
	}
}

int		check_lfork_par(t_params *params, char *line, int index_line)
{
	char	**split;
	char	*arg1;
	int		index;

	split = ft_strsplit(line, SEPARATOR_CHAR);
	check_nbr_arg_lfork(split);
	arg1 = ft_strtrim(split[0]);
	index = -1;
	while (split[++index])
		ft_strdel(&split[index]);
	ft_memdel((void *)&split);
	if (check_type(params, arg1) != DIR_CODE)
	{
		ft_printf("Error: Wrong type of arg1 on instr ");
		ft_printf("%d (lfork)\n", index_line);
		exit(0);
	}
	ft_strdel(&arg1);
	return (1);
}
