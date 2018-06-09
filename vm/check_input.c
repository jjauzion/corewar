/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:05:19 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/09 17:01:56 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				usage(char *prog_name)
{
	ft_printf("Usage : %s [-abcdefghi]\n", prog_name);
}

t_champion			**check_input(int argc, char **argv, t_arena *arena)
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
	arena->nb_champion = 0;
	if (!(arena->option = (t_option*)ft_memalloc(sizeof(t_option))))
		return (NULL);
	arena->option->option = 0;
	while (++i < argc)
	{
		if (option(&i, argc, argv, arena->option) == SUCCESS)
		{
			if (!(champions = realloc(champions, sizeof(t_champion*) * (arena->nb_champion + 1))))
				return (error_ptr(NULL, "error realloc at champion creation"));
			if (!(champions[arena->nb_champion] = read_champ(argv[i])))
			{
				while (arena->nb_champion-- >= 0)
					free(champions[arena->nb_champion]);
				free(champions);
				return (NULL);
			}
			(arena->nb_champion)++;
		}
		else
			return (NULL);
	}
	return (champions);
}
