/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:06:20 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/11 13:06:29 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void check_nbr_arg_fork(char **split)
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

int	check_fork_par(t_params *params, char *line, int index_line)
{
	char	**split;
	char	*arg1;
	int		index;

	split = ft_strsplit(line, SEPARATOR_CHAR);
	check_nbr_arg_fork(split);
	arg1 = ft_strtrim(split[0]);
	index = -1;
	while (split[++index])
		ft_strdel(&split[index]);
	ft_memdel((void *)&split);
	if (check_type(params, arg1) != DIR_CODE)
  {
		ft_printf("Error : Wrong type of arg1 on instr %d (fork)\n", index_line);
		exit(0);
	}
	return (1);
}
