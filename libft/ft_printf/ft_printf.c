/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:27:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 18:19:45 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_delspec(t_spec *spec)
{
	if (spec->attribute)
		ft_strdel(&(spec->attribute));
	if (spec->l_modifier)
		ft_strdel(&(spec->l_modifier));
	if (spec->field)
		ft_strdel(&(spec->field));
}

static int		ft_plain_str(const char **format, int *iscolor, char *plain_str)
{
	int	i;

	i = 0;
	while (**format && **format != '%' && (**format != '{' || !*iscolor))
	{
		*iscolor = 1;
		*plain_str = **format;
		(*format)++;
		plain_str++;
		i++;
	}
	*plain_str = '\0';
	return (i);
}

static int		ft_check_color(const char **format, int *iscolor,
		char *plain_str, int *i)
{
	int	ret;

	ret = 0;
	*iscolor = 1;
	if (**format == '{')
	{
		plain_str[*i] = '\0';
		ret = ft_print_current(plain_str, NULL, ret);
		*i = 0;
		*iscolor = ft_color(format);
	}
	return (ret);
}

static int		ft_loop(const char *format, t_spec *spec,
		char *plain_str, va_list ap)
{
	int		i;
	int		ret;
	int		iscolor;

	ret = 0;
	while (*format && ret >= 0)
	{
		i = 0;
		iscolor = 1;
		ret += ft_check_color(&format, &iscolor, plain_str, &i);
		i += ft_plain_str(&format, &iscolor, plain_str);
		if (*format == '%')
		{
			format++;
			format = ft_parse(ap, format, spec);
			if (ft_get_param(ap, spec))
				ret = -1;
			ret = ft_print_current(plain_str, spec, ret);
		}
		else
			ret = ft_print_current(plain_str, NULL, ret);
		ft_delspec(spec);
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	t_spec	spec;
	va_list	ap;
	char	*plain_str;
	int		ret;

	va_start(ap, format);
	if (!(plain_str = ft_strnew(ft_strlen(format))))
		return (-1);
	spec.attribute = NULL;
	spec.l_modifier = NULL;
	spec.field = NULL;
	spec.width = -1;
	spec.precision = -1;
	spec.c_specifier = 0;
	spec.v_char = 0;
	ret = ft_loop(format, &spec, plain_str, ap);
	ft_strdel(&plain_str);
	va_end(ap);
	return (ret);
}
