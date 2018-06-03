/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni2utf8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:46:47 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/02 16:14:04 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Take a wchar_t as input and convert it to 1, 2, 3 or 4 byte according to
**	the UTF-8 standard.
**	The function allocate a fresh (with malloc(3)) string of char
**	which might be 1, 2, 3 or 4 char lenght and terminated with '\0'.
**
**	Returns:
**	A pointer to this new string is returned.
*/

#include "libft.h"

static int	ft_get_octet(wchar_t c)
{
	int	nb_octet;

	if (WRONG_UTF8(c))
		return (-1);
	nb_octet = ft_getnbofutf8byte(c);
	if ((int)MB_CUR_MAX < nb_octet)
	{
		if (c > 127 && c < 256)
		{
			c = (char)c;
			nb_octet = 1;
		}
		else
			return (-1);
	}
	return (nb_octet);
}

char		*ft_uni2utf8(wchar_t c)
{
	char	*ret;
	int		nb_octet;
	int		i;

	if ((nb_octet = ft_get_octet(c)) < 0)
		return (NULL);
	if (!(ret = ft_strnew(nb_octet)))
		return (NULL);
	if (nb_octet == 1)
		ret[0] = c;
	i = nb_octet;
	while (--i >= 1)
	{
		ret[i] = 0x80 | (c & 0x3F);
		c = c >> 6;
	}
	if (nb_octet == 2)
		ret[0] = 0xC0 | (c & 0x1F);
	if (nb_octet == 3)
		ret[0] = 0xE0 | (c & 0xF);
	if (nb_octet == 4)
		ret[0] = 0xF0 | (c & 0x7);
	return (ret);
}
