/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:51:28 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 18:40:56 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_int_arg(t_var var, t_spec *spec)
{
	intmax_t	arg;

	spec->field = NULL;
	if (ft_strequ(spec->l_modifier, "l") || spec->c_specifier == 'D')
		arg = (long int)var.im;
	else if (ft_strequ(spec->l_modifier, "hh"))
		arg = (char)var.im;
	else if (ft_strequ(spec->l_modifier, "h"))
		arg = (short)var.im;
	else if (ft_strequ(spec->l_modifier, "j"))
		arg = var.im;
	else if (ft_strequ(spec->l_modifier, "ll"))
		arg = (long long int)var.im;
	else if (ft_strequ(spec->l_modifier, "z"))
		arg = (size_t)var.im;
	else if (ft_strequ(spec->l_modifier, "t"))
		arg = (ptrdiff_t)var.im;
	else
		arg = (int)var.im;
	spec->field = ft_imtoa(arg);
	ft_add_precision(spec);
	ft_generate_field(spec);
	return (0);
}
