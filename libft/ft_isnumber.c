/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:52:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/23 11:17:28 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Check if the string given in input contain a well formatted number so that
**	it can be passed safely to ft_atoi function.
**	Returns 1 if the input string contains a well formated number for atoi.
**	Returns 0 otherwise.
**	Example :
**		"	gfkj-235453"		is conisdered bad formated	-> return 0
**		"235453gfdklg"			is conisdered bad formated	-> return 0
**		" 	-235453 		"	is conisdered well formated	-> return 1
*/

#include "libft.h"

int		ft_isnumber(char *str)
{
	while ((*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n' ||
				*str == '\r' || *str == '\f') && *str)
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0' || *str == ' ' || *str == '\t' || *str == '\v' ||
			*str == '\n' || *str == '\r' || *str == '\f')
		return (1);
	else
		return (0);
}
