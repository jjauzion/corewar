/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_arg_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:17:12 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/02 16:13:30 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_wstr_arg(t_var var, t_spec *spec)
{
	char	*tmp;

	if (!var.ws)
		tmp = ft_strdup("(null)");
	else
	{
		if (!(tmp = ft_wstr2str(var.ws, spec->precision)))
		{
			spec->width = -1;
			spec->field = ft_strnew(0);
			return (1);
		}
	}
	if (spec->precision >= 0)
	{
		spec->field = ft_strsub(tmp, 0, spec->precision);
		ft_clean_utf8str(spec->field);
	}
	else
		spec->field = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_generate_wfield(spec);
	return (0);
}

int			ft_str_arg(t_var var, t_spec *spec)
{
	char	*tmp;

	spec->field = NULL;
	if (spec->c_specifier == 'S' || ft_strchr(spec->l_modifier, 'l'))
		return (ft_wstr_arg(var, spec));
	if (!var.s)
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(var.s);
	if (spec->precision >= 0)
		spec->field = ft_strsub(tmp, 0, spec->precision);
	else
		spec->field = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_generate_wfield(spec);
	return (0);
}

int			ft_char_arg(t_var var, t_spec *spec)
{
	spec->field = ft_strnew(0);
	if (spec->c_specifier == 'C' || ft_strchr(spec->l_modifier, 'l'))
	{
		if (WRONG_UTF8(var.wc))
		{
			spec->width = -1;
			return (1);
		}
		if ((int)MB_CUR_MAX < ft_getnbofutf8byte(var.wc))
		{
			if (var.wc < 256)
				spec->v_char = (char)var.wc;
			else
			{
				spec->width = -1;
				return (1);
			}
		}
		else
			spec->v_char = var.wc;
	}
	else
		spec->v_char = (wchar_t)var.c;
	ft_generate_wfield(spec);
	return (0);
}
