/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:23:09 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/18 20:05:32 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	print(t_params *params)
{
	t_instr	*tmp;
	int 	index;

	ft_printf("\n\e[30;48;5;1mDumping annotated program on standard output\n");
	ft_printf("Program size : %d bytes\n", params->header.prog_size);
	ft_printf("Name : '%s'\n", params->header.prog_name);
	ft_printf("Comment : '%s'\e[0m\n\n", params->header.comment);
	tmp = params->instr;
	while (tmp)
	{
		index = -1;
		ft_printf("\e[30;48;5;82mOpcode : [%d]\e[0m\t", tmp->opcode);
		ft_printf("Address(%d)\t", tmp->address);
		ft_printf("Bytes(%d)\n", tmp->nbr_bytes);
		ft_printf("\t\tOCP(%d)\n", tmp->ocp);
		while (++index < tmp->nbr_arg)
		{
			ft_printf("arg[%d] : %s --->\t", index, tmp->arg[index]);
			ft_printf("val[%d] : %d\n", index, tmp->arg_value[index]);
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
}

int		main (int ac, char **av)
{
	int			fd;
	char		*line;
	int			index;
	int			index2;
	t_params	params;

	params.file_name = ft_strsub(av[1], 0, ft_strclen(av[1], '.'));
	if (ac != 2 || !ft_strstr(av[1], ".s"))
	{
		ft_printf("usage : ./asm file.s\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_printf("This file does not exist !\n");
		return (0);
	}
	index = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] && line[0] != COMMENT_CHAR)
			index += 1;
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	lseek(fd, 0, SEEK_SET);
	params.lexer = NULL;
	params.label = NULL;
	params.file_name = ft_strsub(av[1], 0, ft_strlen(av[1]) - 2);
	if (!(params.file = (char **)ft_memalloc(sizeof(char *) * (index + 1))))
		return (0);
	params.file[index] = 0;
	params.file_len = index;
	params.instr = NULL;
	index2 = -1;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] && line[0] != COMMENT_CHAR && !str_is_empty(line))
			params.file[++index2] = line;
		else
			ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	close(fd);
	//From here we got the entire file (line by line) in params.file;
	get_label(&params); //Function to initate the stuct label (name and pos)
	lexer(&params); //Function to clear file of labels, to reach an easier parsing
	get_instr(&params); //Function to get every instruction, their arguments, name etc
	write_bytecode(&params);
	print(&params);
	return (0);
}
