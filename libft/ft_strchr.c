/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:39:43 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/25 12:08:32 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*tracker;
	char		target;

	if (c == 0)
		return (NULL);
	tracker = s;
	target = c;
	while (*tracker != target && *tracker)
		tracker++;
	if (*tracker == target)
		return ((char*)tracker);
	else
		return (NULL);
}
