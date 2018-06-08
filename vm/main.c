/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:30:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/08 09:34:08 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "stdio.h"

/*
int main()
{
	t_op op;

	op.ocp = 0xff;
	check_ocp(&op, 16, NULL);
}
*/

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
	ft_print_mem(arena->mem, MEM_SIZE);
ft_printf("nom champ 1 = %s\n", arena->champions[0]->header.prog_name);
printf("magic champ 1 = %d\n", arena->champions[0]->header.magic);
ft_printf("id champ 1 = %d\n", arena->champions[0]->id);
ft_print_mem(arena->process->reg[0], 4);
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
