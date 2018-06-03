/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:06:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/30 15:48:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H

t_type g_type[] =
{
	{ "dDi", ft_int_arg},
	{ "oOuUxX", ft_uint_arg},
	{ "sS", ft_str_arg},
	{ "cC", ft_char_arg},
	{ "p", ft_ptr_arg},
	{ "%", ft_pct_arg},
	{ " ", ft_usage}
};

#endif
