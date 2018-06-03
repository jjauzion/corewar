/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrcnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:02:32 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 10:10:35 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Alloue (avec malloc(3)) et retourne une chaine de caractère wchar_t
**	La chaine est initialise avec 'size' characteres ’wchar_t c’
**	et termine par un '\0'.
**	Si l’allocation echoue, la fonction renvoie NULL.
*/

#include "libft.h"

wchar_t	*ft_wstrcnew(size_t size, wchar_t c)
{
	wchar_t	*str;
	size_t	i;

	if (!(str = (wchar_t *)malloc((sizeof(wchar_t) * (size + 1)))))
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
