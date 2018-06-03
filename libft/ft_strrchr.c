/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:08:57 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/10 18:29:55 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tracker;
	char		*res;
	char		target;

	tracker = s;
	res = NULL;
	target = c;
	while (*tracker)
	{
		if (*tracker == target)
			res = (char*)tracker;
		tracker++;
	}
	if (*tracker == target)
		return ((char*)tracker);
	else
		return (res);
}
