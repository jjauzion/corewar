/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr2str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:59:43 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 10:10:57 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Convert a wchar_t *str to a char *str formatted according to UTF8 standard.
**	The function allocate a fresh string and returned a pointer to this string.
**	"size" specify the number of wchar_t character to be copied, No more than
**	"size" character from "src" are copied to the new string.
*/

#include "libft.h"

char	*ft_wstr2str(wchar_t *src, int size)
{
	char	*ret;
	char	*tmp;
	char	*ctmp;

	ret = ft_strnew(0);
	if (!src || !ret)
		return (NULL);
	if (!*src)
		return (ret);
	while (*src && size)
	{
		if (!(ctmp = ft_uni2utf8(*src)))
		{
			free(ret);
			return (NULL);
		}
		tmp = ft_strjoin(ret, ctmp);
		free(ctmp);
		free(ret);
		ret = tmp;
		src++;
		size--;
	}
	return (ret);
}
