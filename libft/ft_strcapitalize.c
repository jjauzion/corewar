/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:37:40 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/17 13:33:06 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	if (ft_islower((int)str[0]))
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (!ft_isalnum((int)str[i - 1]) && ft_islower((int)str[i]))
			str[i] -= 32;
		if (ft_isalnum((int)str[i - 1]) && ft_isupper((int)str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}
