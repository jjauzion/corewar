/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:02:00 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/27 19:21:34 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptr_arg(t_var var, t_spec *spec)
{
	char	*tmp;

	if (!(spec->field = ft_uitoa_base(var.uim, 16)))
		return (1);
	ft_add_precision(spec);
	if (!ft_strchr(spec->attribute, '#'))
	{
		tmp = spec->attribute;
		if (!(spec->attribute = ft_strjoin("#", tmp)))
			return (1);
		ft_strdel(&tmp);
	}
	spec->c_specifier = 'x';
	ft_generate_field(spec);
	spec->c_specifier = 'p';
	return (0);
}
