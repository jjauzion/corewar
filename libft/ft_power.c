/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:27:25 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/07 18:27:28 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_power(int nb, int power)
{
	long long int	res;

	res = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (--power)
		res = res * 10;
	return (res);
}
