#include "asm.h"

void	check_name_label(char *str)
{
	int	index;

	index = -1;
	while (str[++index])
	{
		if (!ft_strchr(LABEL_CHARS, str[index]))
		{
			ft_putendl("Error");
			ft_printf("\e[31m%s\e[0m is a wrong name for label\n", str);
			ft_printf("If u may only use those letters: \e[32m%s\e[0m it would be great thanks\n",
				LABEL_CHARS);
			exit(1);
		}
	}
}

t_label *new_label(int pos, char *line)
{
	t_label *new_label;
	int	index;
	char	**split;

	if (!(new_label = (t_label *)ft_memalloc(sizeof(t_label))))
		return (NULL);
	split = ft_strsplit(line, LABEL_CHAR);
	new_label->name = ft_strsub(split[0], 0, ft_strlen(split[0]));
	check_name_label(new_label->name);
	index = -1;
	while (split[++index])
		ft_strdel(&split[index]);
	ft_memdel((void *)&split);
	new_label->pos = pos;
	return (new_label);
}

t_label	*create_label(t_params *params, int pos, char *line)
{
	t_label		*tmp;
	t_label		*save;

	if (params->label == NULL)
	{
		tmp = new_label(pos, line);
		return (tmp);
	}
	else
	{
		tmp = params->label;
		save = tmp;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_label(pos, line);
		return (save);
	}
}

void	get_label(t_params *params)
{
	int	position;
	int	index_file;
	char	*tmp;

	position = 0;
	index_file = 0;
	tmp = NULL;
	while (params->file[index_file][0] == NAME_CMD_STRING[0])
		index_file++;
	index_file--;
	while (params->file[++index_file])
	{
		if (ft_strchr(params->file[index_file], LABEL_CHAR))
		{
			tmp = ft_strchr(params->file[index_file], LABEL_CHAR);
			if ((tmp[1] == '\t' || tmp[1] == ' '
				 || tmp[1] == '\n' || tmp[1] == '\0'))
			{
				params->label = create_label(params, position,
					params->file[index_file]);
			}
		}
		position += 1;
	}
	while (params->label)
	{
		ft_printf("\e[32mName : [%s], pos = [%d]\e[0m\n", params->label->name, params->label->pos);
		params->label = params->label->next;
	}
}