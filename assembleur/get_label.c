/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:23:51 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 16:40:38 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_double_labels(t_params *params, char *name)
{
	t_label	*tmp;

	tmp = params->label;
	if (tmp)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->name, name) == 0)
			{
				ft_printf("Error: Label named \e[31m%s\e[0m ", name);
				ft_printf("already exists!\n");
				exit(0);
			}
			tmp = tmp->next;
		}
	}
}

t_label	*new_label(t_params *params, int pos, char *line)
{
	t_label	*new_label;
	int		index;
	char	**split;

	if (!(new_label = (t_label *)ft_memalloc(sizeof(t_label))))
		return (NULL);
	split = ft_strsplit(line, LABEL_CHAR);
	new_label->name = ft_strsub(split[0], 0, ft_strlen(split[0]));
	check_name_label(new_label->name);
	check_double_labels(params, new_label->name);
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
		tmp = new_label(params, pos, line);
		return (tmp);
	}
	else
	{
		tmp = params->label;
		save = tmp;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_label(params, pos, line);
		return (save);
	}
}

void	get_label_2(t_params *params, char *tmp, int index_file, int position)
{
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
}

void	get_label(t_params *params)
{
	int		position;
	int		index_file;
	char	*tmp;

	position = 0;
	index_file = 0;
	tmp = NULL;
	while (params->file[index_file] &&
		pass_ws(params->file[index_file])[0] == '.')
		index_file++;
	if (params->file_len == index_file)
	{
		ft_printf("Error: Invalid file\n");
		exit(0);
	}
	index_file--;
	get_label_2(params, tmp, index_file, position);
}
