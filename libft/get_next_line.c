/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:23:51 by jjauzion          #+#    #+#             */
/*   Updated: 2018/03/21 10:15:30 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int		ft_flush(char *dst, t_file *f, int *len)
{
	while (f->index < f->ret && f->buff[f->index] != '\n')
	{
		dst[*len] = f->buff[f->index];
		f->index++;
		(*len)++;
	}
	dst[*len] = '\0';
	if (f->index >= f->ret)
		return (0);
	f->index++;
	return (1);
}

static void		*ft_realloc_line(void **src, size_t len, size_t size)
{
	void	*dst;

	if (!(dst = ft_memalloc(len + 1 + size)))
		return (NULL);
	dst = ft_memcpy(dst, *src, len + 1);
	free(*src);
	*src = NULL;
	return (dst);
}

static int		ft_read(char **str, t_file *f, int *len)
{
	while (1)
	{
		f->index = 0;
		if ((f->ret = read(f->fd, f->buff, BUFF_SIZE)) < 0)
			return (ERROR);
		if (f->ret == 0)
		{
			if (*str == '\0')
				ft_strdel(str);
			return (EOFF);
		}
		if (ft_flush(*str, f, len))
			return (EOL);
		*str = (char *)ft_realloc_line((void **)str, *len, BUFF_SIZE + 1);
	}
}

static t_file	*ft_file_lst(const int fd, t_file **f)
{
	t_file	*elm;

	elm = *f;
	while (elm)
	{
		if (elm->fd == fd)
			return (elm);
		elm = elm->next;
	}
	if (!(elm = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if (!(elm->buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	elm->fd = fd;
	elm->ret = 0;
	elm->index = 0;
	elm->buff[0] = '\0';
	elm->next = *f;
	*f = elm;
	return (elm);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*file_lst = NULL;
	t_file			*f;
	char			*str;
	int				status;
	int				len;

	len = 0;
	f = ft_file_lst(fd, &file_lst);
	str = ft_strnew(BUFF_SIZE + ft_strlen(f->buff) - f->index + 1);
	if (!f || !str || !line)
		return (ERROR);
	if (ft_flush(str, f, &len))
	{
		*line = (char *)ft_realloc_line((void**)&str, len, 0);
		return (EOL);
	}
	if ((status = ft_read(&str, f, &len)) == ERROR || (!*str && status == EOFF))
	{
		*line = str;
		if (status == ERROR)
			return (ERROR);
		return (EOFF);
	}
	*line = (char *)ft_realloc_line((void**)&str, len, 0);
	return (EOL);
}
