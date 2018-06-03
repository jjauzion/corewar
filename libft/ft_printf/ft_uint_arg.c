/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:51:52 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 09:41:30 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_base(char spec)
{
	if (spec == 'o' || spec == 'O')
		return (8);
	else if (spec == 'x' || spec == 'X')
		return (16);
	else
		return (10);
}

static uintmax_t	ft_cast_var(t_var var, t_spec *spec)
{
	uintmax_t	arg;

	if (ft_strequ(spec->l_modifier, "l") || ft_strchr("OU", spec->c_specifier))
		arg = (long unsigned int)var.uim;
	else if (ft_strequ(spec->l_modifier, "hh"))
		arg = (unsigned char)var.uim;
	else if (ft_strequ(spec->l_modifier, "h"))
		arg = (short unsigned)var.uim;
	else if (ft_strequ(spec->l_modifier, "j"))
		arg = var.uim;
	else if (ft_strequ(spec->l_modifier, "ll"))
		arg = (unsigned long long int)var.uim;
	else if (ft_strequ(spec->l_modifier, "z"))
		arg = (size_t)var.uim;
	else if (ft_strequ(spec->l_modifier, "t"))
		arg = (ptrdiff_t)var.uim;
	else
		arg = (unsigned int)var.uim;
	return (arg);
}

int					ft_uint_arg(t_var var, t_spec *spec)
{
	uintmax_t	arg;
	int			base;

	base = ft_base(spec->c_specifier);
	spec->field = NULL;
	arg = ft_cast_var(var, spec);
	if (arg == 0 && ft_strchr("xX", spec->c_specifier))
		spec->attribute = ft_str_del_char(&spec->attribute, '#');
	spec->field = ft_uitoa_base(arg, base);
	if (spec->c_specifier == 'X')
		spec->field = ft_strremapi(spec->field, &ft_toupper);
	ft_add_precision(spec);
	ft_generate_field(spec);
	return (0);
}
