/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:25:23 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/04 12:31:22 by jjauzion         ###   ########.fr       */
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
	int			ret;
	void		*ptr;
	int			nb_byte;

	if (!(champion = (t_champion*)ft_memalloc(sizeof(t_champion) * nb_champ)))
		return (NULL);
	nb_byte = sizeof(unsigned int);
	i = 0;
	while (++i < argc)
	{
		if (ft_strstr(argv[i], ".cor"))
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
				return (error_ptr("File not found"));
			if ((ret = read(fd, buff, CHAMP_MAX_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH + 1)) > 
					CHAMP_MAX_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH)
				return (error_ptr("Champion is too big"));
			close(fd);
			ft_printf("ret = %d\n", ret);
			ft_print_mem((void*)buff, ret);
			ptr = &champion->header.magic;
			j = -1;
			while (++j < nb_byte)
				ft_memset(&ptr[nb_byte - 1 - j], (int)buff[j], 1);
			ft_printf("magic = %u\n", champion->header.magic);
			while (buff[j] != 0)
			{
				champion->header.prog_name[j - nb_byte] = buff[j];
				if (j - nb_byte > PROG_NAME_LENGTH)
					return (error_ptr("Programme name is too long\n"));
				j++;
			}
			ft_printf("%s\n", champion->header.prog_name);
			ptr = &champion->header.prog_size;
			j = -1;
			while (++j < nb_byte)
				ft_memset(&ptr[nb_byte - 1 - j], (int)buff[j + nb_byte + PROG_NAME_LENGTH + 1 + 2 + 1], 1);
			ft_printf("prog_size = %u\n", champion->header.prog_size);
			j = -1;
			while (buff[++j + nb_byte * 2 + PROG_NAME_LENGTH + 1 + 2 + 1] != 0)
			{
				champion->header.comment[j] = buff[j + nb_byte * 2 + PROG_NAME_LENGTH + 1 + 2 + 1];
				if (j > COMMENT_LENGTH)
					return (error_ptr("Programme comment is too long\n"));
			}
			ft_printf("%s\n", champion->header.comment);
		}
	}
	return (NULL);
}
