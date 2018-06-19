/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_and_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:01:57 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/19 17:05:38 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_name_and_comment(t_params *params)
{
	int	index;
	int	name;
	int	comment;

	name = 0;
	comment = 0;
	index = -1;
	while (params->file[++index])
	{
		if (ft_strstr(params->file[index], NAME_CMD_STRING))
			name = 1;
		if (ft_strstr(params->file[index], COMMENT_CMD_STRING))
			comment = 1;
	}
	if (!comment)
	{
		ft_printf("Error: No comment in the file!\n");
		exit(0);
	}
	if (!name)
	{
		ft_printf("Error: No name in the file!\n");
		exit(0);
	}
}
