/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:52:59 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/10 18:56:07 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_reg(char *arg)
{
	if (arg[0] == 'r')
	{
		if (0 < ft_atoi(arg + 1) && ft_atoi(arg + 1) <= REG_NUMBER)
		{
			if ((int)ft_strlen(arg) - 1 == ft_nbrlen(ft_atoi(arg + 1), 10))
				return (1);
		}
	}
	return (0);
}

int	check_integer(char *arg)
{
	if (0 <= ft_atoi(arg) && ft_atoi(arg) <= 2147483647)
	{
		if ((int)ft_strlen(arg) == ft_nbrlen(ft_atoi(arg), 10))
			return (1);
	}
	return (0);
}

int	check_dir(t_params *params, char *arg)
{
	if (arg[1] == LABEL_CHAR)
	{
		check_label_name(params, arg + 2);
		return (1);
	}
	else if (arg[0] == DIRECT_CHAR && check_integer(arg + 1))
		return (1);
	return (0);
}

// check_integer negative!!!!!!

int	check_type(t_params *params, char *arg, int type)
{
	(void)params;
	// ft_printf("type: %d\n", type);
	if (type == REG_CODE)
		return(check_reg(arg));
	else if (type == DIR_CODE)
		return(check_dir(params, arg));
	else if (type == IND_CODE)
		return(check_integer(arg));
	else
		return (0);
}
