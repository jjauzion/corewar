/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:42:20 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/14 20:39:36 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	store_name(t_params *params, char *line)
{
	int	index_name;
	int	index_line;

	index_name = -1;
	index_line = -1;

	while (line[++index_line] && line[index_line] != '"')
		;
	while (line[++index_line] && line[index_line] != '"')
	{
		params->header.prog_name[++index_name] = line[index_line];
	}
	while (++index_name < COMMENT_LENGTH)
		params->header.prog_name[index_name] = 0;
}

void	store_comment(t_params *params, char *line)
{
	int	index_comment;
	int	index_line;

	index_comment = -1;
	index_line = -1;

	while (line[++index_line] && line[index_line] != '"')
		;
	while (line[++index_line] && line[index_line] != '"')
		params->header.comment[++index_comment] = line[index_line];
	while (++index_comment < COMMENT_LENGTH)
		params->header.comment[index_comment] = 0;
}

void	get_header(t_params *params)
{
	int		index;
	int 	i2;

	index = -1;
	while (params->file[++index] && index < 2)
	{
		i2 = -1;
		while (params->file[index][++i2] && (params->file[index][i2] == ' '
			|| params->file[index][i2] == '\t'))
			;
		if (ft_strncmp(NAME_CMD_STRING, params->file[index] + i2,
				ft_strlen(NAME_CMD_STRING)) == 0)
			store_name(params, params->file[index]);
		if (ft_strncmp(COMMENT_CMD_STRING, params->file[index] + i2,
				ft_strlen(COMMENT_CMD_STRING)) == 0)
			store_comment(params, params->file[index]);
	}
}

int		get_program_size(t_params *params)
{
	t_instr	*tmp;

	tmp = params->instr;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->address + tmp->nbr_bytes);
}

void	print_header(int file, t_params *params)
{
	get_header(params);
	printbits_int(COREWAR_EXEC_MAGIC, file);
	write(file, params->header.prog_name, PROG_NAME_LENGTH + 4);
	printbits_int(get_program_size(params), file);
	write(file, params->header.comment, COMMENT_LENGTH + 4);
}
