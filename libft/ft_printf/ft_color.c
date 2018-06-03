/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:28:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 10:48:48 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "color_code.h"

int		ft_color(const char **str)
{
	int		i;
	int		j;
	char	*code;

	if (**str != '{')
		return (0);
	i = 0;
	while ((*str)[i] && (*str)[i] != '}')
		i++;
	if (!(*str)[i] || i == 0)
		return (0);
	code = ft_strsub(*str, 1, i - 1);
	j = 0;
	while (!ft_strequ(code, g_color_table[j].code) &&
			!ft_strequ("", g_color_table[j].code))
		j++;
	if (ft_strequ("", g_color_table[j].code))
	{
		ft_strdel(&code);
		return (0);
	}
	ft_putstr(g_color_table[j].ansi);
	*str += i + 1;
	ft_strdel(&code);
	return (1);
}
