/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:47:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/27 18:46:07 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_get_digit(const char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ft_isdigit((*str)[i]))
		i++;
	if (i > 0)
	{
		tmp = ft_strsub(*str, 0, i);
		*str += i;
		i = ft_atoi(tmp);
		ft_strdel(&tmp);
	}
	return (i);
}

char		*ft_get_attribute(const char **format)
{
	char		*valid_attribute;
	int			i;
	char		*attribute;
	char		*ptr;

	valid_attribute = ft_strdup("#0-+ '");
	ptr = (char*)valid_attribute;
	attribute = ft_strnew(ft_strlen(*format) + 1);
	if (!attribute || !valid_attribute)
		return (NULL);
	i = 0;
	while ((ptr = ft_strchr(valid_attribute, (int)(**format))))
	{
		attribute[i] = *ptr;
		(*format)++;
		i++;
	}
	attribute[i] = '\0';
	ft_strdel(&valid_attribute);
	return (attribute);
}

int			ft_get_precision(va_list ap, const char **format)
{
	int	precision;

	if (**format != '.')
		return (-1);
	(*format)++;
	if (**format == '*')
	{
		precision = va_arg(ap, int);
		(*format)++;
	}
	else
		precision = ft_get_digit(format);
	return (precision);
}

char		*ft_get_lmodifier(const char **format)
{
	char	*valid_modifier;
	char	*modifier;
	char	*ptr;

	valid_modifier = ft_strdup("hljtzL");
	ptr = (char*)valid_modifier;
	if (!(modifier = ft_strnew(3)))
		return (NULL);
	if (!(ptr = ft_strchr(valid_modifier, (int)(**format))))
	{
		ft_strdel(&valid_modifier);
		return (modifier);
	}
	modifier[0] = *ptr;
	(*format)++;
	if ((*ptr == 'h' && **format == 'h') || (*ptr == 'l' && **format == 'l'))
	{
		modifier[1] = **format;
		(*format)++;
	}
	ft_strdel(&valid_modifier);
	return (modifier);
}
