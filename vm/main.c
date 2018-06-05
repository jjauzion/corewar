/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:30:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/05 18:18:35 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "stdio.h"

#include "op.c"

int		main(int argc, char **argv)
{
	t_arena		arena;
	t_champion	**champions;
	int			option;

	(void)argv;
	if ((champions = check_input(argc, argv, &option, &arena.nb_champion)) == NULL)
		return (ERROR);
	if (!(arena.mem = (char*)ft_memalloc(MEM_SIZE)))
		return (error_int("main"));
	init_arena(&arena, champions);
	ft_print_mem(arena.mem, MEM_SIZE);
ft_printf("nom champ 1 = %s\n", arena.champions[0]->header.prog_name);
ft_printf("id champ 1 = %d\n", arena.champions[0]->id);
ft_print_mem(arena.process->reg[0], 4);
	run_arena(&arena);
	return (SUCCESS);
}
