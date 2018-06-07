/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:25:23 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/07 16:54:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_champion		*read_champ(char *file)
{
	int			j;
	int			fd;
	char		buff[CHAMP_MAX_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH];
	t_champion	*champion;
	void		*ptr;
	int			nb_byte;
	int			ret;

	nb_byte = sizeof(unsigned int);
	if (!(champion = (t_champion*)malloc(sizeof(t_champion))))
		return (error_ptr(NULL, "malloc error\n"));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (error_ptr(champion, "File not found\n"));
	ret = read(fd, buff, CHAMP_MAX_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH);
	close(fd);
//	ft_print_mem((void*)buff, ret);
	champion->header.magic = mem2int(buff, 4);
/*	ptr = &champion->header.magic;
	j = -1;
	while (++j < nb_byte)
		ft_memset(&ptr[nb_byte - 1 - j], (int)buff[j], 1);*/
//	ft_printf("magic = %u\n", champion->header.magic);
	j = nb_byte;
	while (buff[j] != 0)
	{
		champion->header.prog_name[j - nb_byte] = buff[j];
		if (j - nb_byte > PROG_NAME_LENGTH)
			return (error_ptr(champion, "Programme name is too long\n"));
		j++;
	}
	champion->header.prog_name[j - nb_byte] = '\0';
//	ft_printf("%s\n", champion->header.prog_name);
	ptr = &champion->header.prog_size;
	j = -1;
	while (++j < nb_byte)
		ft_memset(&ptr[nb_byte - 1 - j], (int)buff[j + nb_byte + PROG_NAME_LENGTH + 1 + 2 + 1], 1);
//	ft_printf("prog_size = %u\n", champion->header.prog_size);
	if (champion->header.prog_size > CHAMP_MAX_SIZE)
		return (error_ptr(champion, "Champion's code is too large\n"));
	j = -1;
	while (buff[++j + nb_byte * 2 + PROG_NAME_LENGTH + 1 + 2 + 1] != 0)
	{
		champion->header.comment[j] = buff[j + nb_byte * 2 + PROG_NAME_LENGTH + 1 + 2 + 1];
		if (j > COMMENT_LENGTH)
			return (error_ptr(champion, "Programme comment is too long\n"));
	}
	champion->header.comment[j] = '\0';
//	ft_printf("%s\n", champion->header.comment);
	if (!(champion->code = ft_memalloc(champion->header.prog_size)))
		return (error_ptr(champion, "malloc error\n"));
	ft_memcpy(champion->code, &buff[nb_byte * 2 + PROG_NAME_LENGTH + 1 + COMMENT_LENGTH + 1 + 6],
			champion->header.prog_size);
//	ft_print_mem((void*)champion->code, champion->header.prog_size);
	return (champion);
}
