/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:55:54 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 18:42:03 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "specifier.h"

int		ft_get_param(va_list ap, t_spec *spec)
{
	int		i;
	t_var	var;

	var = ft_get_arg(ap, spec);
	i = 0;
	while (!ft_strchr(g_type[i].type, (int)spec->c_specifier) &&
			g_type[i].type[0] != ' ')
		i++;
	if (g_type[i].fct(var, spec))
		return (1);
	else
		return (0);
}

int		ft_pct_arg(t_var var, t_spec *spec)
{
	(void)var;
	spec->field = ft_strdup("%");
	ft_generate_wfield(spec);
	return (0);
}

int		ft_usage(t_var var, t_spec *spec)
{
	(void)var;
	spec->field = ft_strcnew(1, spec->c_specifier);
	ft_generate_wfield(spec);
	return (0);
}
