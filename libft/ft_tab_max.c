/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:47:14 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/12 15:06:45 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_max(int *tab, int nb_elm)
{
	int		i;
	int		max;

	if (!tab || nb_elm <= 0)
		return (0);
	max = tab[0];
	i = 0;
	while (++i < nb_elm)
	{
		if (max < tab[i])
			max = tab[i];
	}
	return (max);
}
