/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:52:59 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 16:47:58 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_reg(char *arg)
{
	int	index;

	index = 0;
	if (arg[0] == 'r')
	{
		if (arg[1] == '0')
		{
			index = 1;
			while (arg[index] == '0')
				index += 1;
			index -= 1;
		}
		if (0 < ft_atoi(arg + 1) && ft_atoi(arg + 1) <= REG_NUMBER)
		{
			if ((int)ft_strlen(arg) - index - 1 ==
				ft_nbrlen(ft_atoi(arg + 1), 10))
				return (REG_CODE);
		}
	}
	return (0);
}

int	check_integer(char *arg)
{
	int		index;

	if (ft_strchr(arg, '-'))
	{
		index = 0;
		while (arg[++index])
		{
			if (!ft_isdigit(arg[index]))
				return (0);
		}
	}
	else
	{
		index = -1;
		while (arg[++index])
		{
			if (!ft_isdigit(arg[index]))
				return (0);
		}
	}
	return (IND_CODE);
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

int	check_ind(t_params *params, char *arg)
{
	if (arg[0] == LABEL_CHAR)
	{
		check_label_name(params, arg + 1);
		return (IND_CODE);
	}
	else if (check_integer(arg))
		return (IND_CODE);
	return (0);
}

int	check_type(t_params *params, char *arg)
{
	if (check_reg(arg))
		return (check_reg(arg));
	else if (check_dir(params, arg))
		return (check_dir(params, arg));
	else if (check_ind(params, arg))
		return (check_ind(params, arg));
	else
		return (0);
}
