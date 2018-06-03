/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:41:31 by smortier          #+#    #+#             */
/*   Updated: 2018/06/03 18:54:28 by smortier         ###   ########.fr       */
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

void		lexer(t_params *params)
{
	int		index;

	index = 0;
	while (params->file[index][0] == '.')
		index += 1; //on zap les comments
	index--;
	while (params->file[++index])
		params->lexer = create_lexer(params, params->file[index]);
	//ft_printf("\e[31m%s\e[0m\n", params->file[index]);
	while (params->lexer)
	{
		ft_printf("\e[32m Line = [%s]\e[0m\n", params->lexer->line);
		params->lexer = params->lexer->next;
	}
}
