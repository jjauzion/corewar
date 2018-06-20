/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:04:22 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/19 17:08:37 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_nbr_arg_zjmp(char **split)
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

int			check_zjmp_par(t_params *params, char *line, int index_line)
{
	char	**split;
	char	*arg1;
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
	(void)index_line;
	ft_strdel(&arg1);
	return (1);
}
