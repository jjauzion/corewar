/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:35:50 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/21 14:35:14 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_get_sign(t_spec spec)
{
	char	sign;

	sign = '\0';
	if (ft_strchr("cCpsSuUOoxX", spec.c_specifier))
	{
		if (ft_strchr(spec.attribute, '#') && ft_strchr("xX", spec.c_specifier))
			sign = 'x';
		return (sign);
	}
	if (ft_strchr(spec.attribute, ' '))
		sign = ' ';
	if (ft_strchr(spec.attribute, '+'))
		sign = '+';
	if (spec.field[0] == '-')
		sign = '-';
	return (sign);
}

void	ft_shift_string(char *arg, char c, char option, int width)
{
	int		len;
	int		i;

	if (!arg)
		return ;
	if (!(len = ft_strlen(arg)))
		return ;
	if (option == 'r')
	{
		while (--width)
			arg[width] = arg[width - 1];
		arg[0] = c;
	}
	if (option == 'l')
	{
		i = -1;
		while (++i < len - 1)
			arg[i] = arg[i + 1];
		arg[len - 1] = c;
	}
}

void	ft_apply_sign(char *arg, char sign, int width)
{
	int		i;

	if (!sign || sign == 'x')
		return ;
	i = 0;
	while (!ft_isdigit(arg[i]) && arg[i])
		i++;
	if (i == 0)
		ft_shift_string(arg, sign, 'r', width);
	else
		arg[i - 1] = sign;
}

int		ft_width(t_spec *spec, int sign_len)
{
	int		len;

	if (ft_strchr("Cc", spec->c_specifier))
		spec->width -= ft_getnbofutf8byte(spec->v_char);
	len = ft_strlen(spec->field);
	len = len + sign_len;
	if (spec->width > len)
		return (spec->width);
	else
		return (len);
}
