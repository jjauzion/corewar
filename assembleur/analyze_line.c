/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:24:32 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/07 19:07:02 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	analyze_line(t_params *params, char *line)
{
	line = skip_whitespace(line);
	if (ft_strncmp("live", line, 4) == 0 && check_live_par(line) == 1)
		save_live(params, line);
	else if (ft_strncmp("ld", line, 2) == 0 && check_ld_par(line) == 1)
		save_ld(params, line);
	else if (ft_strncmp("st", line, 2) == 0 && check_st_par(line) == 1)
		save_st(params, line);
	else if (ft_strncmp("add", line, 3) == 0 && check_add_par(line) == 1)
		save_add(params, line);
	else if (ft_strncmp("sub", line, 3) == 0 && check_sub_par(line) == 1)
		save_sub(params, line);
	else if (ft_strncmp("and", line, 3) == 0 && check_and_par(line) == 1)
		save_and(params, line);
	else if (ft_strncmp("or", line, 2) == 0 && check_or_par(line) == 1)
		save_or(params, line);
	else if (ft_strncmp("xor", line, 3) == 0 && check_xor_par(line) == 1)
		save_xor(params, line);
	else if (ft_strncmp("zjmp", line, 4) == 0 && check_zjmp_par(line) == 1)
		save_zjmp(params, line);
	else if (ft_strncmp("ldi", line, 3) == 0 && check_ldi_par(line) == 1)
		save_ldi(params, line);
	else if (ft_strncmp("sti", line, 3) == 0 && check_sti_par(line) == 1)
		save_sti(params, line);
	else if (ft_strncmp("fork", line, 4) == 0 && check_fork_par(line) == 1)
		save_fork(params, line);
	else if (ft_strncmp("lld", line, 3) == 0 && check_lld_par(line) == 1)
		save_lld(params, line);
	else if (ft_strncmp("lldi", line, 4) == 0 && check_lldi_par(line) == 1)
		save_lldi(params, line);
	else if (ft_strncmp("lfork", line, 5) == 0 && check_lfork_par(line) == 1)
		save_lfork(params, line);
	else if (ft_strncmp("aff", line, 3) == 0 && check_aff_par(line) == 1)
		save_aff(params, line);
	else
		ft_error(line);
}
