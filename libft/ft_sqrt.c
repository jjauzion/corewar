/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:26:07 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/24 14:43:42 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calcul la racine carre d'un nombre. et retourne sa valeur exacte si la
**
**	Option :
**	-exact : La fonction retourne la racine carre si celle ci est entiere,
**	si la racine est reelle retourne -1
**	-sup : retourne la valeur exacte si la racine est entiere ou sa valeur
**	arrondi a l'entier superieur sinon.
**	-inf : retourne la valeur exacte si la racine est entiere ou sa valeur
**	arrondi a l'entier inferieur sinon.
*/

#include "libft.h"

int		ft_sqrt(int nb, char *option)
{
	double	sqrt;
	double	sqrt2;
	double	s;
	int		res;

	if (nb < 1 || (!ft_strequ(option, "-exact") && !ft_strequ(option, "-sup")
				&& !ft_strequ(option, "-inf")))
		return (-1);
	sqrt = (double)nb / 2;
	sqrt2 = (double)nb;
	while (sqrt2 - sqrt > 0.01 || sqrt2 - sqrt < -0.01)
	{
		sqrt2 = sqrt;
		s = (nb - sqrt * sqrt) / (2 * sqrt);
		sqrt = sqrt + s - s * s / (2 * (sqrt + s));
	}
	res = sqrt;
	if (res * res == nb)
		return (res);
	if (ft_strequ(option, "-sup"))
		return (res + 1);
	if (ft_strequ(option, "-inf"))
		return (res);
	return (-1);
}
