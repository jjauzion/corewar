/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_del_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:48:30 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/08 12:16:15 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Delete all character in str that matches c
**	A new string is created (with malloc(3)) and the string given in arg
**	is deleted with ft_strdel.
**	A pointer to the begining of the new string is returned.
*/

#include "libft.h"

char	*ft_str_del_char(char **str, char c)
{
	char	*res;
	int		i;
	int		j;

	if (!str || !*str)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(*str) - ft_count_cinstr(*str, c))))
		return (NULL);
	i = -1;
	j = 0;
	while ((*str)[++i])
	{
		if ((*str)[i] != c)
		{
			res[j] = (*str)[i];
			j++;
		}
	}
	ft_strdel(str);
	return (res);
}
