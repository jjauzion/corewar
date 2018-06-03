/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:02:27 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/15 13:01:31 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	FT_STREXT
**	Re-allocate memory to extend an existing string lenght
**	The new string length will be "len" + "size"
**	The original string s is copied to the first len characters
**	of the new string
**	'\0' is added at the len + 1 character of the new string
**	A pointer to the new string is returned
**	The original memory allocated to input string "s" is freed and s is modified
**  to point to the nez string
*/

char	*ft_strext(char **s, size_t len, size_t size)
{
	char	*tmp;
	size_t	i;

	if (!(tmp = (char *)malloc(sizeof(char) * (len + size))))
		return (NULL);
	i = 0;
	while (s[0][i])
	{
		tmp[i] = s[0][i];
		i++;
	}
	tmp[i] = '\0';
	free(*s);
	*s = tmp;
	return (*s);
}
