/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <smortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:41:31 by smortier          #+#    #+#             */
/*   Updated: 2018/06/18 20:02:58 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

t_lexer		*new_lexer(char *line)
{
	t_lexer		*new_lexer;

	if (!(new_lexer = (t_lexer *)ft_memalloc(sizeof(t_lexer))))
		return (NULL);
	new_lexer->line = line;
	return (new_lexer);
}

t_lexer		*create_lexer(t_params *params, char *line)
{
	t_lexer		*tmp;
	t_lexer		*save;

	ft_printf("LINE :[%s]\n", line);
	if (params->lexer == NULL)
	{
		tmp = new_lexer(line);
		return (tmp);
	}
	else
	{
		tmp = params->lexer;
		save = tmp;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lexer(line);
		return (save);
	}
}

char		*parse_line(char *line)
{
	char	*parsed;
	char	*tmp;
	int		index;

	parsed = line;
	ft_printf("%s\n", line);
	if (ft_strchr(line, LABEL_CHAR))
	{
		index = -1;
		while (line[++index] && line[index] != LABEL_CHAR)
			;
		if (index && line[index - 1] && (line[index - 1] == ' ' || line[index - 1] == '\t')) //WE MIGHT CHANGE THIS with tabs and spaces
			return (line);
		tmp = ft_strchr(line, LABEL_CHAR);
		if (!str_is_empty(tmp + 1) && line[index - 1] != DIRECT_CHAR)
		{
			return (tmp + 1);
		}
		else if (str_is_empty(tmp + 1))
			return ("    ");
	}
	return (line);
}

void		lexer(t_params *params)
{
	int		index;

	index = 0;
	while (pass_ws(params->file[index])[0] == '.')
		index += 1;
	index -= 1;
	while (params->file[++index])
		params->lexer = create_lexer(params, parse_line(params->file[index]));
}
