/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:35:05 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/08 10:29:29 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	*error_ptr(void *ptr, char *msg)
{
	if (ptr)
		free(ptr);
	ft_printf("%s", msg);
	return (NULL);
}

int		error_int(char *msg)
{
	perror(msg);
	return (ERROR);
}
