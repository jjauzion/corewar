/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_current.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:27:43 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/25 20:18:29 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_current(char *plain_str, t_spec *spec, int ret)
{
	if (ret < 0)
		return (ret);
	ft_putstr(plain_str);
	ret += ft_strlen(plain_str);
	if (!spec)
		return (ret);
	if (ft_strchr("cC", spec->c_specifier) && ft_strchr(spec->attribute, '-'))
		ret += ft_putwchar(spec->v_char);
	ft_putstr(spec->field);
	ret += spec->width;
	if (ft_strchr("cC", spec->c_specifier) && !ft_strchr(spec->attribute, '-'))
		ret += ft_putwchar(spec->v_char);
	return (ret);
}
