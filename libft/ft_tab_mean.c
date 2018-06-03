/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_mean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:55:39 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/01 18:23:19 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_mean(int *tab, int nb_elm)
{
	int		i;
	int		sum;

	if (!tab || nb_elm <= 0)
		return (0);
	sum = 0;
	i = -1;
	while (++i < nb_elm)
		sum += tab[i];
	return (sum / nb_elm);
}
