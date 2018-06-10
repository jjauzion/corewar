/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:24:32 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/10 15:22:55 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	analyze_line(t_params *params, char *line, int index_line)
{
	char	**split;
	int		index;

	split = ft_split_whitespaces(line);
	ft_printf("first word: %s\n", split[0]);
	// ft_printf("secon word: %s\n", split[1]);

	(void)params;
	if (ft_strncmp("live", split[0], 4) == 0 && check_live_par(params, line + 4,
			index_line) == 1)
		// save_live(params, line + 4);
		;
	// else if (ft_strncmp("ld", split[0], 2) == 0 && check_ld_par(line) == 1)
	// 	save_ld(params, line);
	// else if (ft_strncmp("st", split[0], 2) == 0 && check_st_par(line) == 1)
	// 	save_st(params, line);
	// else if (ft_strncmp("add", split[0], 3) == 0 && check_add_par(line) == 1)
	// 	save_add(params, line);
	// else if (ft_strncmp("sub", split[0], 3) == 0 && check_sub_par(line) == 1)
	// 	save_sub(params, line);
	// else if (ft_strncmp("and", split[0], 3) == 0 && check_and_par(line) == 1)
	// 	save_and(params, line);
	// else if (ft_strncmp("or", split[0], 2) == 0 && check_or_par(line) == 1)
	// 	save_or(params, line);
	// else if (ft_strncmp("xor", split[0], 3) == 0 && check_xor_par(line) == 1)
	// 	save_xor(params, line);
	// else if (ft_strncmp("zjmp", split[0], 4) == 0 && check_zjmp_par(line) == 1)
	// 	save_zjmp(params, line);
	// else if (ft_strncmp("ldi", split[0], 3) == 0 && check_ldi_par(line) == 1)
	// 	save_ldi(params, line);
	// else if (ft_strncmp("sti", split[0], 3) == 0 && check_sti_par(line) == 1)
	// 	save_sti(params, line);
	// else if (ft_strncmp("fork", split[0], 4) == 0 && check_fork_par(line) == 1)
	// 	save_fork(params, line);
	// else if (ft_strncmp("lld", split[0], 3) == 0 && check_lld_par(line) == 1)
	// 	save_lld(params, line);
	// else if (ft_strncmp("lldi", split[0], 4) == 0 && check_lldi_par(line) == 1)
	// 	save_lldi(params, line);
	// else if (ft_strncmp("lfork", split[0], 5) == 0 && check_lfork_par(line) == 1)
	// 	save_lfork(params, line);
	// else if (ft_strncmp("aff", split[0], 3) == 0 && check_aff_par(line) == 1)
	// 	save_aff(params, line);
	// else
	// 	ft_error(line);
	index = -1;
	while (split[++index])
		ft_strdel(&split[index]);
	ft_memdel((void **)&split);
}
