/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:58:20 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/08 11:55:13 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoui(intmax_t n, uintmax_t *nbr)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		*nbr = (uintmax_t)(n * -1);
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

static int	ft_get_size(intmax_t nbr)
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

char		*ft_imtoa(intmax_t n)
{
	char			*str;
	uintmax_t		nbr;
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
