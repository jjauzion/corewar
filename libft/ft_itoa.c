/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:46:11 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/08 11:54:09 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoui(int n, unsigned int *nbr)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		*nbr = (unsigned int)(n * -1);
	}
	else
		*nbr = n;
	return (sign);
}

static void	ft_applysign(int i, int sign, char *str)
{
	if (sign < 0)
	{
		str[i + 1] = '-';
		str[i + 2] = '\0';
	}
	else
		str[i + 1] = '\0';
}

static int	ft_get_size(int nbr)
{
	int	size;

	size = 1;
	while (nbr >= 10 || nbr <= -10)
	{
		nbr = nbr / 10;
		size++;
	}
	if (nbr < 0)
		return (size + 1);
	else
		return (size);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	int				sign;
	int				i;
	int				size;

	size = ft_get_size(n);
	nbr = 0;
	sign = ft_itoui(n, &nbr);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (nbr >= 10)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	str[i] = nbr % 10 + '0';
	ft_applysign(i, sign, str);
	str = ft_strrev(str);
	return (str);
}
