/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:05:19 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/04 17:31:18 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				usage(char *prog_name)
{
	ft_printf("Usage : %s [-abcdefghi]\n", prog_name);
}

t_champion			**check_input(int argc, char **argv, int *opt, int *nb_champ)
{
	int			i;
	t_champion	**champions;

	if (argc <= 1)
	{
		usage(argv[0]);
		return (NULL);
	}
	i = 0;
	champions = NULL;
	*nb_champ = 0;
	while (++i < argc)
	{
		if (option(&i, argv, "adsv", opt) == ERROR)
		{
			if (!(champions = realloc(champions, sizeof(t_champion*) * (*nb_champ + 1))))
				return (error_ptr(NULL, "error realloc"));
			if (!(champions[*nb_champ] = read_champ(argv[i])))
			{
				while (*nb_champ-- >= 0)
					free(champions[*nb_champ]);
				free(champions);
				return (NULL);
			}
			(*nb_champ)++;
		}
	}
	return (champions);
}
