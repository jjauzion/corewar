/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:25:23 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/03 19:09:15 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_champion		*read_champ(int argc, char **argv, int nb_champ)
{
	int			i;
	int			j;
	int			fd;
	char		buff[CHAMP_MAX_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH];
	t_champion	*champion;
	int			tmp;

	if (!(champion = (t_champion*)ft_memalloc(sizeof(t_champion) * nb_champ)))
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		if (ft_strstr(argv[i], ".cor"))
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
				return (error_ptr("File not found"));
			if (read(fd, buff, CHAMP_MAX_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH) == 0)
				return (error_ptr("Champion is too big"));
			j = -1;
			tmp = (int)*buff;
			ft_printf("tmp = %d\n", tmp);
		}
	}
	return (NULL);
}
