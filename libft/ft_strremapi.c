/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:02:37 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/08 12:18:07 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Applique la fonction f à chaque caractère de la chaine de caractères
**	passée en paramètre en modifiant cette derniere.
*/

#include "libft.h"

char	*ft_strremapi(char *s, int (*f)(int))
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
