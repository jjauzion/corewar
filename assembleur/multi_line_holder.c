/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_line_holder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:03:22 by smortier          #+#    #+#             */
/*   Updated: 2018/08/12 18:40:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*multi_line_holder(int fd, char *line)
{
	if (!ft_strchr(line, '"'))
		exit(0);
	if (!ft_strncmp(line, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)))
	{
		if (ft_strchr(ft_strchr(line, '"') + 1, '"'))
			return (line);
		else
			return (get_all_comment_line(fd, line));
	}
	else if (!ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		if (ft_strchr(ft_strchr(line, '"') + 1, '"'))
			return (line);
		else
			return (get_all_name_line(fd, line));
	}
	else
		exit(0);
}
