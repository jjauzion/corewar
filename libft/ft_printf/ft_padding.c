/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:10:48 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/13 14:06:00 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_padding(char *arg, char option, int sign_len, int width)
{
	int		len;
	char	c;
	int		nb2pad;

	if (!arg || !(option == ' ' || option == '0' || option == '-'))
		return ;
	len = ft_strlen(arg);
	c = (option == '-') ? ' ' : option;
	nb2pad = width;
	if (option != '-')
	{
		if (option == '0')
			nb2pad = nb2pad - sign_len;
		arg = ft_strrev(arg);
	}
	while (len < nb2pad)
		arg[len++] = c;
	if (option != '-')
		arg = ft_strrev(arg);
}
