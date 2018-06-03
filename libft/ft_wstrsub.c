/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:23:54 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/13 17:26:45 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un tronçon de la
**	chaine de caractères passée en paramètre. Le tronçon commence à l’index
**	"start" et à pour longueur "len". Si "start" et "len" ne désignent pas un
**	tronçon de chaine valide, le comportement est indéterminé.
**	Si l’allocation échoue, la fonction renvoie NULL.
*/

#include "libft.h"

wchar_t	*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(ret = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
