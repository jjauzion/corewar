#include "asm.h"
#include "libft.h"

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
	if (!(params.file = (char **)ft_memalloc(sizeof(char *) * index + 1)))
		return (0);
	params.file[index] = NULL;
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
	//lexer(&params);
	get_label(&params);
}
