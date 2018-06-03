/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:01:59 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/14 12:04:27 by jjauzion         ###   ########.fr       */
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

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(ret = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > ft_strlen(s))
		return (ret);
	i = 0;
	while (s[i + start] && i < len)
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
