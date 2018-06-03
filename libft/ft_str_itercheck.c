/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_itercheck.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:37:28 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/30 18:48:31 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Test each character of the string "s" with the function "f" given in input
**	Returns 1 is "f" returns 1 for every character.
**	Returns 0 otherwise.
**	Returns -1 in case of error.
*/

#include "libft.h"

int		ft_str_itercheck(char *s, int (*f)(int))
{
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (-1);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (!f((int)s[i]))
			return (0);
		i++;
	}
	return (1);
}
