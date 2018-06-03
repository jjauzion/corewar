/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:51:15 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 10:33:57 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				ft_apply_mask(wchar_t c, unsigned char *wc,
		int nb_octet)
{
	int		i;

	if (nb_octet == 1)
		wc[0] = c;
	i = -1;
	while (++i < nb_octet - 1)
	{
		wc[i] = 0x80 | (c & 0x3F);
		c = c >> 6;
	}
	if (nb_octet == 2)
		wc[1] = 0xC0 | (c & 0x1F);
	if (nb_octet == 3)
		wc[2] = 0xE0 | (c & 0xF);
	if (nb_octet == 4)
		wc[3] = 0xF0 | (c & 0x7);
}

static unsigned char	*ft_init(wchar_t c)
{
	unsigned char	*wc;
	int				i;

	if (WRONG_UTF8(c))
		return (NULL);
	if (!(wc = (unsigned char*)malloc(sizeof(char) * 4)))
		return (NULL);
	i = 0;
	while (++i < 4)
		wc[i] = '\0';
	return (wc);
}

int						ft_putwchar(wchar_t c)
{
	int				nb_octet;
	unsigned char	*wc;
	int				i;
	int				ret;

	if (c < 0)
	{
		write(1, &c, 1);
		return (1);
	}
	if (!(wc = ft_init(c)))
		return (-1);
	nb_octet = ft_getnbofutf8byte(c);
	ft_apply_mask(c, wc, nb_octet);
	ret = 0;
	i = nb_octet;
	while (--i >= 0)
	{
		write(1, &(wc[i]), 1);
		ret++;
	}
	free(wc);
	return (ret);
}
