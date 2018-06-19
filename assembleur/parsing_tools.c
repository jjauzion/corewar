/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spliesei <spliesei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:16:46 by spliesei          #+#    #+#             */
/*   Updated: 2018/06/19 17:39:10 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_all_comment_line(int fd, char *line)
{
	char	*ret;
	char	*line2;

	ret = (char *)ft_memalloc(sizeof(char) * COMMENT_LENGTH + 1);
	ft_strcat(ret, line);
	ft_strcat(ret, "\n");
	while (get_next_line(fd, &line2) == 1 && !ft_strchr(line2, '"'))
	{
		ft_strcat(ret, line2);
		ft_strcat(ret, "\n");
		ft_strdel(&line2);
	}
	ft_strcat(ret, line2);
	ft_strdel(&line2);
	return (ret);
}

char	*pass_ws(char *str)
{
	int	index;

	index = -1;
	while (str[++index] && (str[index] == ' ' || str[index] == '\t'))
		;
	return (str + index);
}
