/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbofutf8byte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:26:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 10:34:32 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculate the number of bytes required to format the wchar_t given in input
**	to the utf8 format.
**	In case var is negative the function return 1.
*/

#include "libft.h"

static int			ft_bit2oct(int nb)
{
	if (nb <= 7)
		return (1);
	if (nb <= 11)
		return (2);
	if (nb <= 16)
		return (3);
	return (4);
}

int					ft_getnbofutf8byte(wchar_t var)
{
	int		active_bits;

	if (var < 0)
		return (1);
	active_bits = 0;
	while (var)
	{
		var = var >> 1;
		active_bits++;
	}
	return (ft_bit2oct(active_bits));
}
