/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:04:22 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/11 13:45:07 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void check_nbr_arg_ldi(char **split)
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

int			check_zjmp_par(t_params *params, char *line, int index_line)
{
	char	**split;
	char	*arg1;
	char	*arg2;
	char	*arg3;
	int		index;

	split = ft_strsplit(line, SEPARATOR_CHAR);
	check_nbr_arg_zjmp(split);
	arg1 = ft_strtrim(split[0]);
	index = -1;
	while (split[++index])
		ft_strdel(&split[index]);
	ft_memdel((void *)&split);
	if (check_type(params, arg1) != DIR_CODE)
	{
		ft_printf("Error : Wrong type of arg1 on instr %d\n", index_line);
		exit(0);
	}
	ft_printf("first: [%s]\n", arg1);
	ft_printf("arg_type 1: %d\n", check_type(params, arg1));
	(void)index_line;
	return (1);
}
