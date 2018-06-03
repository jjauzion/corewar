/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:33:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/02 16:09:52 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_value(va_list ap, const char **format)
{
	int	value;

	if (**format == '*')
	{
		value = va_arg(ap, int);
		(*format)++;
	}
	else
		value = ft_get_digit(format);
	return (value);
}

static int	ft_check_width(t_spec *spec, int value)
{
	char	*tmp;

	if (value < 0)
	{
		value = value * -1;
		if (!ft_strchr(spec->attribute, '-'))
		{
			tmp = spec->attribute;
			spec->attribute = ft_strjoin("-", tmp);
			ft_strdel(&tmp);
		}
	}
	return (value);
}

const char	*ft_parse(va_list ap, const char *format, t_spec *spec)
{
	int		tmp;

	spec->attribute = ft_get_attribute(&format);
	tmp = ft_get_value(ap, &format);
	if (spec->attribute[0] == '\0')
		if (*format == '$')
		{
			format++;
			ft_strdel(&spec->attribute);
			spec->attribute = ft_get_attribute(&format);
			tmp = ft_get_value(ap, &format);
		}
	spec->width = ft_check_width(spec, tmp);
	spec->precision = ft_get_precision(ap, &format);
	spec->l_modifier = ft_get_lmodifier(&format);
	spec->c_specifier = *format;
	if (ft_strchr("fFgGeE", spec->c_specifier) && (spec->precision < 0))
		spec->precision = 6;
	if (ft_strchr("diouxXDOU", spec->c_specifier)
			&& ft_strchr(spec->attribute, '0') && spec->precision >= 0)
		spec->attribute = ft_str_del_char(&spec->attribute, '0');
	format = (*format) ? format + 1 : format;
	return (format);
}
