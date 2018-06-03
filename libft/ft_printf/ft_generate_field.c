/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_field.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:55:21 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 18:18:04 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_sign_len(char sign)
{
	if (sign)
		if (sign == 'x')
			return (2);
		else
			return (1);
	else
		return (0);
}

static void	ft_pad(t_spec *spec, int sign_len, int width)
{
	if (ft_strchr(spec->attribute, '-'))
		ft_padding(spec->field, '-', sign_len, width);
	else if (ft_strchr(spec->attribute, '0'))
		ft_padding(spec->field, '0', sign_len, width);
	else
		ft_padding(spec->field, ' ', sign_len, width);
}

void		ft_generate_field(t_spec *spec)
{
	int		len;
	char	sign;
	int		width;
	int		sign_len;

	sign = ft_get_sign(*spec);
	sign_len = ft_get_sign_len(sign);
	if (sign == '-')
		ft_shift_string(spec->field, '\0', 'l', 0);
	if (ft_strchr(spec->attribute, '#'))
		ft_apply_ohashtag(spec);
	if (!spec->field)
		return ;
	len = ft_strlen(spec->field);
	width = ft_width(spec, sign_len);
	if (width != len)
		if (!(spec->field = (char *)ft_realloc((void **)&spec->field,
					len + 1, width - len + 1)))
			return ;
	ft_pad(spec, sign_len, width);
	ft_apply_sign(spec->field, sign, width);
	if (ft_strchr(spec->attribute, '#'))
		ft_apply_0xhashtag(spec, width);
	spec->width = width;
}
