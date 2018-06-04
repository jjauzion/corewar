/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:30:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/04 17:41:10 by jjauzion         ###   ########.fr       */
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
	ft_printf("nom champ 1 = %s\n", champions[0]->header.prog_name);
	//ft_printf("nom champ 2 = %s\n", champions[1]->header.prog_name);
	write_champions(&arena, champions);
	ft_print_mem(arena.mem, MEM_SIZE);
//	run_arena(&arena);
	return (SUCCESS);
}
