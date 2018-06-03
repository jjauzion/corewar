/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:46:21 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 10:42:06 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_CODE_H
# define COLOR_CODE_H

t_color g_color_table[] =
{
	{"black", "\x1b[30m"},
	{"red", "\x1b[31m"},
	{"green", "\x1b[32m"},
	{"yellow", "\x1b[33m"},
	{"blue", "\x1b[34m"},
	{"magenta", "\x1b[35m"},
	{"cyan", "\x1b[36m"},
	{"white", "\x1b[37m"},
	{"brightblue", "\x1b[94m"},
	{"eoc", "\x1b[0m"},
	{"", "not a code"}
};

#endif
