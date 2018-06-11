/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:23:57 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/11 14:07:00 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void check_nbr_arg_ld(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
		;
	if (i != 2)
	{
		ft_printf("Error:\n");
		exit (0);
	}
}

int	check_ld_par(t_params *params, char *line, int index_line)
{
	char	**split;
	char	*arg1;
	char	*arg2;
	int		index;

	split = ft_strsplit(line, SEPARATOR_CHAR);
	check_nbr_arg_ld(split);
	arg1 = ft_strtrim(split[0]);
	arg2 = ft_strtrim(split[1]);
	index = -1;
	while (split[++index])
		ft_strdel(&split[index]);
	ft_memdel((void *)&split);
	if (check_type(params, arg1) != DIR_CODE && check_type(params, arg1) != IND_CODE)
	{
		ft_printf("Error : Wrong type of arg1 on instr %d\n", index_line);
		exit(0);
	}
	if (check_type(params, arg2) != REG_CODE)
	{
		ft_printf("Error : Wrong type of arg2\n");
		exit(0);
	}
	ft_printf("first: [%s]\n", arg1);
	ft_printf("second: [%s]\n", arg2);
	ft_printf("arg_type 1: %d\n", check_type(params, arg1));
	ft_printf("arg_type 2: %d\n", check_type(params, arg2));
	(void)index_line;
	return (1);
}
