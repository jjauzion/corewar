/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:05:19 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/25 18:01:08 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				*usage(char *prog_name)
{
	ft_printf("Usage : %s [-d N -dcoplk] <champion1.cor> <...>\n", prog_name);
	ft_printf("\t -d N\t: Dumps memory after N cycles then exits\n", prog_name);
	ft_printf("\t -c  \t: Show cycles\n", prog_name);
	ft_printf("\t -o  \t: Show operations\n", prog_name);
	ft_printf("\t -p  \t: Show pc movement (except for jumps)\n", prog_name);
	ft_printf("\t -l  \t: Show lives\n", prog_name);
	ft_printf("\t -k  \t: Show deaths\n", prog_name);
	return (NULL);
}

static t_champion	**add_champ(t_champion **champions, t_arena *arena, char *c)
{
	if (arena->nb_champion >= MAX_PLAYERS)
		return (error_ptr(NULL, "Error: too many champions\n"));
	if (!(champions = realloc(champions,
					sizeof(t_champion*) * (arena->nb_champion + 1))))
		return (error_ptr(NULL, "error realloc at champion creation"));
	if (!(champions[arena->nb_champion] = read_champ(c)))
	{
		while (arena->nb_champion > 0)
		{
			free(champions[arena->nb_champion - 1]->code);
			free(champions[arena->nb_champion - 1]);
			(arena->nb_champion)--;
		}
		free(champions);
		return (NULL);
	}
	(arena->nb_champion)++;
	return (champions);
}

t_champion			**check_input(int argc, char **argv, t_arena *arena)
{
	int			i;
	t_champion	**champions;
	int			ret;

	if (argc <= 1)
		return (usage(argv[0]));
	i = 0;
	champions = NULL;
	arena->nb_champion = 0;
	if (!(arena->option = (t_option*)ft_memalloc(sizeof(t_option))))
		return (NULL);
	arena->option->option = 0;
	while (++i < argc)
	{
		if ((ret = option(&i, argc, argv, arena->option)) == 1)
		{
			if (!(champions = add_champ(champions, arena, argv[i])))
				return (NULL);
		}
		else if (ret == ERROR)
			return (usage(argv[0]));
	}
	return (champions);
}
