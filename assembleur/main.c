/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:23:09 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/14 20:07:58 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	print(t_params *params)
{
	t_instr	*tmp;
	int 	index;

	tmp = params->instr;
	while (tmp)
	{
		index = -1;
		ft_printf("Opcode : [%d]\n", tmp->opcode);
		ft_printf("Adress : [%d]\n", tmp->address);
		ft_printf("Bytes  : [%d]\n", tmp->nbr_bytes);
		ft_printf("OCP    : [%d]\n", tmp->ocp);
		while (++index < tmp->nbr_arg)
		{
			ft_printf("arg[%d] : %s\n", index, tmp->arg[index]);
			ft_printf("val[%d] : %d\n", index, tmp->arg_value[index]);
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
}

int		main (int ac, char **av)
{
	int		fd;
	char	*line;
	int		index;
	int		index2;
	t_params params;

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
	// params.file_name = ft_strsub(av[1], 0, ft_strclen(av[1], '.'));
	if (!(params.file = (char **)ft_memalloc(sizeof(char *) * (index + 1))))
		return (0);
	params.file[index] = 0;
	params.instr = NULL;
	index2 = -1;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] && line[0] != '#' && !str_is_empty(line))
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
	print(&params);
	write_bytecode(&params);
	return (0);
}
