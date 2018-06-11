/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:31:50 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/10 18:46:40 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// int	check_comment(char *line)
// {
// 	if (line[0] == COMMENT_CHAR)
// 		return (1);
// 	return (0);
// }
//
// int	check_label_chars(char *line, int i)
// {
// 	while (--i >= 0)
// 	{
// 		if (ft_strchr(LABEL_CHARS, line[i]) == NULL)
// 			return (0);
// 	}
// 	return (1);
// }
//
// int	check_label(char *line)
// {
// 	int	i;
//
// 	i = 0;
// 	while (line[i] && line[i] != LABEL_CHAR)
// 		i++;
// 	if (line[i])
// 	{
// 		if (check_label_chars(line, i))
// 			return (1);
// 	}
// 	return (0);
// }


void check_label_name(t_params *params, char *name)
{
	int		ok;
	t_label *tmp;

	ok = 0;
	tmp = params->label;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, name, ft_str_ws_len(name)))
		{
			if (ft_strlen(tmp->name) == ft_strlen(name))
				ok = 1;
		}
		tmp = tmp->next;
	}
	if (ok != 1)
	{
		ft_printf("Error: This label does not exist : %s\n", name);
		exit(0);
	}
}

// trim label name

int	check_int(t_params *params, char *line)
{
	int		tmp;

	tmp = ft_atoi(line);
	if (*line == LABEL_CHAR)
		check_label_name(params, line + 1);
	else if (ft_strncmp(ft_itoa(tmp), line, ft_str_ws_len(line)))
	{
		ft_printf("Error: %s : is probably an overflow\n", line);
		exit(0);
	}
	return (1);
}

int	check_live_plus(t_params *params, char *line, int index_line)
{
	int		index;

	index = -1;
	while (line[++index] && ((line[index] >= '0' &&
		line[index] <= '9') || line[index] == '-'))
		;
	if (line[index] == LABEL_CHAR)
		check_label_name(params, line + index + 1);
	else if (index != ft_str_ws_len(line))
	{
		ft_printf("Error: Unexpected token in instruction %d :\e[31m%s\e[0m\n", index_line, line + index);
		exit(0);
	}
	return (1);
}

int	check_live_par(t_params *params, char *line, int index_line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == DIRECT_CHAR)
	{
		if (check_live_plus(params, line + i + 1, index_line)
			&& check_int(params, line + i + 1)) // Checks if the Number in the string is an int.
			return (1);
		else
		{
			ft_printf("Error with : %s\n", line);
			exit (0);
		}
	}
	ft_printf("Error: Wrong usage of live: (live (DIRECT))\n");
	exit (0);
}
