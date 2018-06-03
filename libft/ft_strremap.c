/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:48:50 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/08 12:17:36 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Applique la fonction f à chaque caractère de la chaine de caractères
**	passée en paramètre en modifiant cette derniere.
*/

#include "libft.h"

char	*ft_strremap(char *s, char (*f)(char))
{
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		s[i] = f(s[i]);
		i++;
	}
	return (s);
}
