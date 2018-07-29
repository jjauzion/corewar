/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_and_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:01:57 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/21 16:25:42 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	clear_comments(char **line)
{
	int		index;

	index = 0;
	if ((ft_strchr(*line, COMMENT_CHAR) || ft_strchr(*line, COMMENT_CHAR_TWO))
		&& !ft_strstr(*line, COMMENT_CMD_STRING) &&
		!ft_strstr(*line, NAME_CMD_STRING))
	{
		while ((*line)[index] && ((*line)[index] != COMMENT_CHAR &&
				(*line)[index] != COMMENT_CHAR_TWO))
			index += 1;
		(*line)[index] = '\0';
	}
}

int		check_name_com(char *name)
{
	int		index;

	index = -1;
	if (!ft_strchr(name, '"'))
	{
		ft_printf("Error: syntax error on name\n");
		exit(0);
	}
	while (name[++index] && name[index] != '"')
	{
		if (name[index] == COMMENT_CHAR)
		{
			ft_printf("Error: %c in name\n", COMMENT_CHAR);
			exit(0);
		}
	}
	return (1);
}

int		check_com_com(char *comment)
{
	int		index;

	index = -1;
	if (!ft_strchr(comment, '"'))
	{
		ft_printf("Error: syntax error on name\n");
		exit(0);
	}
	while (comment[++index] && comment[index] != '"')
	{
		if (comment[index] == COMMENT_CHAR)
		{
			ft_printf("Error: %c in name\n", COMMENT_CHAR);
			exit(0);
		}
	}
	return (1);
}

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
		!ft_strncmp(pass_ws(params->file[index]), NAME_CMD_STRING,
			ft_strlen(NAME_CMD_STRING)) ? name +=
						check_name_com(params->file[index]) : 0;
		!ft_strncmp(pass_ws(params->file[index]), COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)) ? comment +=
				check_com_com(params->file[index]) : 0;
	}
	if (comment != 1)
		ft_printf("Error: Number of comments in the file is wrong!\n");
	if (name != 1)
		ft_printf("Error: Number of names in the file is wrong!\n");
	if (name != 1 || comment != 1)
		exit(0);
	index = -1;
	while (params->file[++index])
		clear_comments(&(params->file[index]));
}
