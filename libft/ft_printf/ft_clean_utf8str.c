/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_utf8str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 12:44:50 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/22 12:56:34 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_clean_utf8str(char *str)
{
	int i;
	int	count;

	if (MB_CUR_MAX == 1)
		return ;
	i = ft_strlen(str) - 1;
	if (!(str[i] & 0x80))
		return ;
	count = 0;
	while ((str[i] & 0xC0) == 0x80)
	{
		i--;
		count++;
	}
	if (((str[i] & 0xF0) == 0xF0) && count == 3)
		return ;
	if (((str[i] & 0xF0) == 0xE0) && count == 2)
		return ;
	if (((str[i] & 0xF0) == 0xC0) && count == 1)
		return ;
	str[i] = '\0';
}
