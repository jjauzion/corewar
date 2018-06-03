/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:13:31 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/13 12:35:55 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Search string "s" for a character that doesn't match with "c"
**	If a character different from "c" is found in "s" then a pointer to this
**	character is returned.
**	Otherwise, NULL is returned.
*/

#include "libft.h"

char	*ft_strnchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s == (char)c && *s)
		s++;
	if (!*s)
		return (NULL);
	else
		return ((char *)s);
}
