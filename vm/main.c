/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:30:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/03 15:20:10 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "stdio.h"

int		main()
{
	int		i;

	i = 5;
	printf("op_tab[i].name = %s\n", op_tab[i].name);
	printf("op_tab[i].arg_type[0] = %i\n", op_tab[i].arg_type[0]);
	printf("op_tab[i].arg_type[1] = %i\n", op_tab[i].arg_type[1]);
	printf("op_tab[i].arg_type[2] = %i\n", op_tab[i].arg_type[2]);
}
