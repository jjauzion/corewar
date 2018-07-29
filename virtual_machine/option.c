/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:05:31 by jjauzion          #+#    #+#             */
/*   Updated: 2018/07/29 18:00:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		is_valid_option(char *arg)
{
	int		i;

	if (!arg || arg[0] != '-' || arg[1] == '\0')
		return (ERROR);
	if (ft_strchr(VALID_OPT_WITH_VAL, (int)arg[1]))
	{
		if (ft_strlen(arg) > 2)
			return (ERROR);
		else
			return (SUCCESS);
	}
	i = 0;
	while (arg[++i])
	{
		if (!ft_strchr(VALID_OPT, (int)arg[i]))
			return (ERROR);
	}
	if (i <= 1)
		return (ERROR);
	else
		return (SUCCESS);
}

static int		set_option(int *index, t_option *option, char *arg1, char *arg2)
{
	int		tmp;

	if (!arg1 || !option)
		return (ERROR);
	arg1++;
	while (*arg1)
	{
		if (*arg1 == 'd' || *arg1 == 'n')
		{
			if (arg2 == NULL || !ft_isnumber(arg2))
				return (ERROR);
			else if (*arg1 == 'd')
				option->d_cycle = ft_atoi(arg2);
			else if (*arg1 == 'n')
				option->champ_order = arg2;
			(*index)++;
		}
		tmp = 1;
		tmp = tmp << (*arg1 - 'a');
		option->option = option->option | tmp;
		arg1++;
	}
	return (SUCCESS);
}

void			print_option(int option)
{
	int		bit;
	int		i;
	int		mask;

	mask = 1 << 31;
	i = 0;
	while (++i <= 32)
	{
		bit = option & mask;
		if (bit == 0)
			ft_putchar('0');
		else
			ft_putchar('1');
		if (i == 8 || i == 16 || i == 24)
			ft_putchar(' ');
		option = option << 1;
	}
	ft_putchar('\n');
}

int				opt_is_set(int option, char test_opt)
{
	int mask;

	mask = 1 << (test_opt - 'a');
	if ((option & mask) != 0)
		return (1);
	else
		return (0);
}

int				option(int *index, int argc, char **argv, t_option *option)
{
	int		valid;

	if (argv[*index][0] == '-')
	{
		if ((valid = is_valid_option(argv[*index])) == ERROR)
			return (1);
		if (*index + 1 < argc)
			return (set_option(index, option, argv[*index], argv[*index + 1]));
		else
			return (set_option(index, option, argv[*index], NULL));
	}
	return (1);
}
