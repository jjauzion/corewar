/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:35:05 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/03 17:40:15 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	*error_ptr(char *msg)
{
	ft_printf("%s\n", msg);
	return (NULL);
}

int		error_int(char *msg)
{
	perror(msg);
	return (ERROR);
}
