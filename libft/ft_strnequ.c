/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:29:45 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/16 20:02:00 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (-1);
	if (n == 0)
		return (1);
	while (*s1 == *s2 && *s1 && *s2 && (n - 1) > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (*s1 == *s2)
		return (1);
	else
		return (0);
}
