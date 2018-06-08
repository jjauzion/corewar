/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:31:50 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/08 14:20:21 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_comment(char *line)
{
	line = skip_whitespace(line);
	if (line[0] == COMMENT_CHAR)
		return (1);
	return (0);
}

int	check_label_chars(char *line, int i)
{
	while (--i >= 0)
	{
		if (ft_strchr(LABEL_CHARS, line[i]) == NULL)
			return (0);
	}
	return (1);
}

int	check_label(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != LABEL_CHAR)
		i++;
	if (line[i])
	{
		if (check_label_chars(line, i))
			return (1);
	}
	return (0);
}

int	check_live_par(char *line)
{
	int	i;

	i = 0;
	line = skip_whitespace(line);
	if (line[i] == DIRECT_CHAR)
	{
		if (check_int(&line[i + 1])) // Checks if the Number in the string is an int.
			return (1);
		else
			error_live(line);
	}
	return (0);
}

int	check_ld_par(char *line)
{

}

int	check_st_par(char *line)
{

}

int	check_add_par(char *line)
{

}

int	check_sub_par(char *line)
{

}

int	check_and_par(char *line)
{

}

int	check_or_par(char *line)
{

}

int	check_xor_par(char *line)
{

}

int	check_zjmp_par(char *line)
{

}

int	check_ldi_par(char *line)
{

}

int	check_sti_par(char *line)
{

}

int	check_fork_par(char *line)
{

}

int	check_lld_par(char *line)
{

}

int	check_lldi_par(char *line)
{

}

int	check_lfork_par(char *line)
{

}

int	check_aff_par(char *line)
{

}
