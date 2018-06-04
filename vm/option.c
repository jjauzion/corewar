/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:05:31 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/04 17:05:12 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		is_valid_option(char *arg, char *valid_option)
{
	int		i;

	if (!arg || arg[0] != '-')
		return (ERROR);
	i = 0;
	while (arg[++i])
	{
		if (!ft_strchr(valid_option, (int)arg[i]))
			return (ERROR);
	}
	if (i <= 1)
		return (ERROR);
	else
		return (SUCCESS);
}

static void		set_option(int *option, char *arg)
{
	int		tmp;

	if (!arg || !option)
		return ;
	arg++;
	while (*arg)
	{
		tmp = 1;
		tmp = tmp << (*arg - 'a');
		*option = *option | tmp;
		arg++;
	}
}

void		print_option(int option)
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

int				option(int *index, char **argv, char *valid_option, int *option)
{
	int		valid;

	if (argv[*index][0] == '-')
	{
		if ((valid = is_valid_option(argv[*index], valid_option)) == ERROR)
		{
			ft_putstr("Invalid Option\n");
			return (ERROR);
		}
		set_option(option, argv[*index]);
		(*index)++;
		return (SUCCESS);
	}
	return (ERROR);
}
