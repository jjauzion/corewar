/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_itercheck.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:45:05 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/31 13:48:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Test "size" values in the table "tab"  with the function "f" given in input
**	Returns 1 is "f" returns 1 for all value.
**	Returns 0 otherwise.
**	Returns -1 in case of error.
*/

#include "libft.h"

int		ft_tab_itercheck(int *tab, int size, int (*f)(int))
{
	size_t	i;

	if (!tab || !f || size < 1)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (!f((int)tab[i]))
			return (0);
		i++;
	}
	return (1);
}
