/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:59:00 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 16:21:50 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_nbr_arg_st(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
		;
	if (i != 2)
	{
		ft_printf("Error: Wrong number of arguments!\n");
		exit(0);
	}
}

void	check_st_errors(t_params *params, char *arg1, char *arg2)
{
	if (check_type(params, arg1) != REG_CODE)
	{
		ft_printf("Error: Wrong type of arg1 for (st)!\n");
		exit(0);
	}
	if (check_type(params, arg2) != REG_CODE &&
		check_type(params, arg2) != IND_CODE)
	{
		ft_printf("Error: Wrong type of arg2 for (st)!\n");
		exit(0);
	}
}

int		check_st_par(t_params *params, char *line, int index_line)
{
	char	**split;
	char	*arg1;
	char	*arg2;
	int		index;

	split = ft_strsplit(line, SEPARATOR_CHAR);
	check_nbr_arg_st(split);
	arg1 = ft_strtrim(split[0]);
	arg2 = ft_strtrim(split[1]);
	index = -1;
	while (split[++index])
		ft_strdel(&split[index]);
	ft_memdel((void *)&split);
	check_st_errors(params, arg1, arg2);
	(void)index_line;
	ft_strdel(&arg1);
	ft_strdel(&arg2);
	return (1);
}
