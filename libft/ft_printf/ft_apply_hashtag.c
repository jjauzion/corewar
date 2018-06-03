/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hashtag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:00:34 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/18 17:39:48 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_apply_ohashtag(t_spec *spec)
{
	char	*tmp;

	if (ft_strchr("oO", spec->c_specifier) && spec->field[0] != '0')
	{
		tmp = ft_strjoin("0", spec->field);
		free(spec->field);
		spec->field = tmp;
	}
}

void	ft_apply_0xhashtag(t_spec *spec, int width)
{
	int		i;

	if (spec->c_specifier == 'x' || spec->c_specifier == 'X')
	{
		i = 0;
		while (!ft_ishexa(spec->field[i]) && spec->field[i])
			i++;
		if (i == 0)
		{
			ft_shift_string(spec->field, spec->c_specifier, 'r', width);
			ft_shift_string(spec->field, '0', 'r', width);
		}
		else
		{
			spec->field[i - 1] = spec->c_specifier;
			spec->field[i - 2] = '0';
		}
	}
}
