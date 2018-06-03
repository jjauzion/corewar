/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:37:53 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/18 17:20:42 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_copy_w_zero(char *dst, char *src, int sign, int nb_zero)
{
	int		i;
	int		j;

	if (sign)
		dst[0] = '-';
	i = -1 + sign;
	j = -1 + sign;
	while (++i < nb_zero + sign)
		dst[i] = '0';
	while (src[++j])
		dst[i++] = (src[j]);
	dst[i] = '\0';
}

void		ft_add_precision(t_spec *spec)
{
	int		sign;
	int		len;
	char	*ret;

	if (spec->precision < 0)
		return ;
	sign = (spec->field[0] == '-') ? 1 : 0;
	if (spec->field[0] == '0')
		spec->field[0] = '\0';
	len = (sign) ? ft_strlen(spec->field) - 1 : ft_strlen(spec->field);
	if (len >= spec->precision)
		return ;
	if (!(ret = ft_strnew(spec->precision + sign)))
		return ;
	ft_copy_w_zero(ret, spec->field, sign, spec->precision - len);
	free(spec->field);
	spec->field = ret;
}
