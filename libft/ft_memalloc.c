/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:41:44 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/11 17:24:47 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	char	*tmp;

	if (!(ptr = malloc(size)))
		return (NULL);
	tmp = ptr;
	while (size)
	{
		*tmp = 0;
		tmp++;
		size--;
	}
	return (ptr);
}
