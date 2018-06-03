/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:09:36 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/16 10:55:46 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = *(str + i);
		*(str + i) = *(str + (len - 1 - i));
		*(str + (len - 1 - i)) = tmp;
		i++;
	}
	return (str);
}
