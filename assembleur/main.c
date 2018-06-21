/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:23:09 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 14:50:29 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	check_main_params(int ac, char **av)
{
	char	*tmp;

	tmp = NULL;
	if (ac == 3 && ft_strcmp(av[1], "-a") == 0)
	{
		tmp = av[1];
		av[1] = av[2];
		av[2] = tmp;
	}
	else if (ac == 3)
	{
		ft_printf("usage : ./asm (-flag) file.s\nAllowed flag: -a\n");
		exit(0);
	}
	if ((ac != 2 && ac != 3) || !ft_strstr(av[1], ".s"))
	{
		ft_printf("usage : ./asm (-flag) file.s\nAllowed flag: -a\n");
		exit(0);
	}
}

void	get_file(t_params *params, int fd, int index)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] && (pass_ws(line)[0] != COMMENT_CHAR && pass_ws(line)[0]
			!= COMMENT_CHAR_TWO) && !str_is_empty(line))
		{
			if (ft_strstr(line, COMMENT_CMD_STRING))
			{
				if (ft_strchr(ft_strchr(line, '"') + 1, '"'))
					params->file[++index] = line;
				else
				{
					params->file[++index] = get_all_comment_line(fd, line);
					ft_memdel((void **)&line);
				}
			}
			else
				params->file[++index] = line;
		}
		else
			ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
}

void	init_params(t_params *params, int index, char **av)
{
	params->lexer = NULL;
	params->label = NULL;
	params->instr = NULL;
	params->file_name = ft_strsub(av[1], 0, ft_strlen(av[1]) - 2);
	if (!(params->file = (char **)ft_memalloc(sizeof(char *) * (index + 1))))
		exit(0);
	params->file[index] = 0;
	params->file_len = index;
}

void	assembler(t_params *params, int ac)
{
	check_name_and_comment(params);
	get_label(params);
	lexer(params);
	get_instr(params);
	write_bytecode(params);
	if (ac == 3)
		print(params);
	ft_printf("Champion compiled! :)\n");
}

int		main(int ac, char **av)
{
	int			fd;
	char		*line;
	int			index;
	t_params	params;

	check_main_params(ac, av);
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_printf("This file does not exist !\n");
		return (0);
	}
	index = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] && (line[0] != COMMENT_CHAR && line[0] != COMMENT_CHAR_TWO))
			index += 1;
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	lseek(fd, 0, SEEK_SET);
	init_params(&params, index, av);
	get_file(&params, fd, -1);
	close(fd);
	assembler(&params, ac);
	return (0);
}
