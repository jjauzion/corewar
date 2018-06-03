/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_wfield.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:01:28 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/25 15:43:05 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_generate_wfield(t_spec *spec)
{
	int		len;
	int		width;

	len = ft_strlen(spec->field);
	width = ft_width(spec, 0);
	if (width != len)
		if (!(spec->field = (char *)ft_realloc((void **)&spec->field,
						len + 1, width - len + 1)))
			return ;
	if (ft_strchr(spec->attribute, '-'))
		ft_padding(spec->field, '-', 0, width);
	else if (ft_strchr(spec->attribute, '0'))
		ft_padding(spec->field, '0', 0, width);
	else
		ft_padding(spec->field, ' ', 0, width);
	spec->width = width;
}
