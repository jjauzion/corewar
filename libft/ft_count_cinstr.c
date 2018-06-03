/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_cinstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:00:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/08 12:04:10 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_cinstr(const char *str, char c)
{
	int		count;
	int		i;

	if (!str)
		return (-1);
	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}
