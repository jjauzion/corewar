/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:03:01 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/22 11:48:09 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Alloue (avec malloc(3)) et retourne une chaine de caractère “fraiche”
**	La chaine est initialise avec 'size' charactere	’char c’
**	et termine par un '\0'.
**	Si l’allocation echoue, la fonction renvoie NULL.
*/

#include "libft.h"

char	*ft_strcnew(size_t size, char c)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
