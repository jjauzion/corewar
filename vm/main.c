/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:30:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/08 18:54:46 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "stdio.h"

int		main(int argc, char **argv)
{
	t_arena		*arena;
	t_champion	**champions;
	int			option;

	(void)argv;
	if (!(arena = (t_arena*)ft_memalloc(sizeof(t_arena))))
		return (ERROR);
	if ((champions = check_input(argc, argv, &option, &arena->nb_champion)) == NULL)
		return (ERROR);
	if (!(arena->mem = (t_uchar*)ft_memalloc(MEM_SIZE)))
		return (error_int("main"));
	init_arena(arena, champions);
SPAM2((arena->mem, MEM_SIZE));
SPAM(("nom champ 1 = %s\n", arena->champions[0]->header.prog_name));
SPAM(("magic champ 1 = %d\n", arena->champions[0]->header.magic));
SPAM(("id champ 1 = %d\n", arena->champions[0]->id));
	run_arena(arena);
	free(arena->mem);
	while (arena->nb_champion)
	{
		free(arena->champions[arena->nb_champion - 1]->code);
		free(arena->champions[arena->nb_champion - 1]);
		arena->nb_champion--;
	}
	free(arena->champions);
	return (SUCCESS);
}
