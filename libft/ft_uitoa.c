/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:46:11 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 19:14:41 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(unsigned int nbr)
{
	int	size;

	size = 1;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

char		*ft_uitoa(unsigned int n)
{
	char			*str;
	int				i;

	if (!(str = (char *)malloc(sizeof(char) * (ft_get_size(n) + 1))))
		return (NULL);
	i = 0;
	while (n >= 10)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	str[i] = n % 10 + '0';
	str[i + 1] = '\0';
	str = ft_strrev(str);
	return (str);
}
