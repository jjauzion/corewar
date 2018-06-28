/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ws_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 10:07:20 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/28 10:08:04 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_ws_len(char *str)
{
	int		index;

	index = -1;
	while (str[++index] && str[index] != ' ' && str[index] != '\t'
		&& str[index] != '\n')
		;
	return (index);
}
