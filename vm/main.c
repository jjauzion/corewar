/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:30:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/03 19:07:09 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "stdio.h"

#include "op.c"

int		main(int argc, char **argv)
{
	t_arena		arena;
	t_champion	*champions;
	int			nb_champ;

	(void)argv;
//	if (argc < 2 || (nb_champ = check_input(argv)) == 0)
//	{
//		usage();
//		return (ERROR);
//	}
	if ((champions = read_champ(argc, argv, nb_champ)) == NULL)
		return (ERROR);
//	if (!(arena.mem = (char*)ft_memalloc(MEM_SIZE)))
//		return (error_int("main"));
//	arena.players = create_champion(champions);
//	run_arena(&arena);
	return (SUCCESS);
}
