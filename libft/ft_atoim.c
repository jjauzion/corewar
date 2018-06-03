/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:56:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/26 16:56:46 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoim(const char *str)
{
	long long int	nbr;
	int				sign;

	sign = 1;
	nbr = 0;
	while ((*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n'
				|| *str == '\r' || *str == '\f') && *str)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (intmax_t)(*str - 48);
		str++;
	}
	return (nbr * (intmax_t)sign);
}
