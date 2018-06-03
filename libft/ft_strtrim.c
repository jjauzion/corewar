/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:01:30 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/16 19:49:26 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:
**	Alloue (avec malloc(3)) et retourne une copie de la chaine
**	passée en paramètre sans les espaces blancs au debut et à la
**	fin de cette chaine. On considère comme espaces blancs les
**	caractères ’ ’, ’\n’ et ’\t’. Si s ne contient pas d’espaces
**	blancs au début ou à la fin, la fonction renvoie une copie de
**	s. Si l’allocation echoue, la fonction renvoie NULL.
*/

char		*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			len;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	if (!s[i])
		return (ft_strsub(s, 0, 0));
	start = i;
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	len = i - start + 1;
	return (ft_strsub(s, start, len));
}
