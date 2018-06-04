/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:10:36 by exam              #+#    #+#             */
/*   Updated: 2018/03/13 11:16:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"

int		main(int argc, char **argv)
{
	int		i;
	int		valid;
	int		option;

	if (argc <= 1)
	{
		ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
		return (1);
	}
	option = 0;
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			if ((valid = is_valid_option(argv[i])) <= 0)
			{
				if (valid == -1)
					ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
				else
					ft_putstr("Invalid Option\n");
				return (1);
			}
			else
				set_option(&option, argv[i]);
		}
	}
	print_option(option);
	return (0);
}
