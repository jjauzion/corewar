/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:38:35 by smortier          #+#    #+#             */
/*   Updated: 2018/06/05 12:51:57 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_instr(t_params *params)
{
	t_lexer		*file;

	file = params->lexer;
	while (file)
	{
		ft_printf("line = [%s]\n", file->line);
		file = file->next;
	}
}
