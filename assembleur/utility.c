/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:52:59 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/12 13:34:01 by spliesei         ###   ########.fr       */
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
				return (REG_CODE);
		}
	}
	return (0);
}

int	check_integer(char *arg)
{
	if (ft_strchr(arg, '-'))
	{
		if (-2147483647 <= ft_atoi(arg) && ft_atoi(arg) <= 0)
		{
			if ((int)ft_strlen(arg + 1) == ft_nbrlen(ft_atoi(arg + 1), 10))
				return (IND_CODE);
		}
	}
	else if (0 <= ft_atoi(arg) && ft_atoi(arg) <= 2147483647)
	{
		if ((int)ft_strlen(arg) == ft_nbrlen(ft_atoi(arg), 10))
			return (IND_CODE);
	}
	return (0);
}

int	check_dir(t_params *params, char *arg)
{
	if (arg[1] == LABEL_CHAR)
	{
		check_label_name(params, arg + 2);
		return (DIR_CODE);
	}
	else if (arg[0] == DIRECT_CHAR && check_integer(arg + 1))
		return (DIR_CODE);
	return (0);
}

// check_integer negative!!!!!!

int	check_type(t_params *params, char *arg)
{
	(void)params;
	if (check_reg(arg))
		return (check_reg(arg));
	else if (check_dir(params, arg))
		return (check_dir(params, arg));
	else if (check_integer(arg))
		return (check_integer(arg));
	else
		return (0);
}
