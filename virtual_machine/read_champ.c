/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:25:23 by jjauzion          #+#    #+#             */
/*   Updated: 2018/08/11 11:15:15 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static	t_champion	*progname(t_champion *champion, t_uchar *buff, int nb_byte)
{
	int j;

	j = nb_byte - 1;
	while (buff[++j] != 0)
	{
		champion->header.prog_name[j - nb_byte] = buff[j];
		if (j - nb_byte > PROG_NAME_LENGTH)
			return (error_ptr(champion, "Programme name is too long\n"));
	}
	champion->header.prog_name[j - nb_byte] = '\0';
	return (champion);
}

static t_champion	*check_buf(t_champion *champion, t_uchar *buff, int nb_byte)
{
	int		j;
	void	*ptr;

	if (!progname(champion, buff, nb_byte))
		return (NULL);
	ptr = &champion->header.prog_size;
	j = -1;
	while (++j < nb_byte)
		ft_memset(&ptr[nb_byte - 1 - j],
				(int)buff[j + nb_byte + PROG_NAME_LENGTH + 1 + 2 + 1], 1);
	if (champion->header.prog_size > CHAMP_MAX_SIZE)
		return (error_ptr(champion, "Champion's code is too large\n"));
	if (champion->header.prog_size == 0)
		return (error_ptr(champion, "No champion's code in file\n"));
	j = -1;
	while (buff[++j + nb_byte * 2 + PROG_NAME_LENGTH + 1 + 2 + 1] != 0)
	{
		champion->header.comment[j] = buff[j + nb_byte * 2 +
			PROG_NAME_LENGTH + 1 + 2 + 1];
		if (j > COMMENT_LENGTH)
			return (error_ptr(champion, "Programme comment is too long\n"));
	}
	champion->header.comment[j] = '\0';
	return (champion);
}

static t_champion	*check(t_champion *champion, t_uchar *buff, int nb_byte,
		int ret)
{
	if ((champion->header.magic = mem2int(buff, 0, S_UINT)) !=
			COREWAR_EXEC_MAGIC)
		return (error_ptr(champion, "Wrong magic number\n"));
	if (!check_buf(champion, buff, nb_byte))
		return (NULL);
	if (ret - (2 * nb_byte + PROG_NAME_LENGTH + COMMENT_LENGTH + 8) !=
			(int)champion->header.prog_size)
		return (error_ptr(champion, "Champion's code size error\n"));
	return (champion);
}

t_champion			*read_champ(char *file)
{
	int			fd;
	t_uchar		buff[16 + CHAMP_MAX_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH];
	t_champion	*champion;
	int			nb_byte;
	int			ret;

	nb_byte = (int)S_UINT;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (error_ptr(NULL, "File not found\n"));
	if (!(champion = (t_champion*)ft_memalloc(sizeof(t_champion))))
		return (error_ptr(NULL, "malloc error\n"));
	ret = read(fd, (void*)buff, 2 * nb_byte + CHAMP_MAX_SIZE +
			PROG_NAME_LENGTH + COMMENT_LENGTH + 8);
	if (ret < (2 * nb_byte + PROG_NAME_LENGTH + COMMENT_LENGTH + 8))
		return (error_ptr(champion, "File is too small to be a champion\n"));
	close(fd);
	if (!check(champion, buff, nb_byte, ret))
		return (NULL);
	if (!(champion->code = (t_uchar*)ft_memalloc(champion->header.prog_size)))
		return (error_ptr(champion, "malloc error\n"));
	ft_memcpy(champion->code, &buff[nb_byte * 2 + PROG_NAME_LENGTH +
			1 + COMMENT_LENGTH + 1 + 6], champion->header.prog_size);
	return (champion);
}
