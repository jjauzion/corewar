/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:18:21 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/19 11:45:10 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_realloc_index(unsigned int **index,
		unsigned int size, int add)
{
	unsigned int	*tmp1;
	unsigned int	*tmp2;
	unsigned int	i;

	if (!(tmp1 = (unsigned int *)malloc(sizeof(unsigned int) * (size + add))))
		return (1);
	if (!(tmp2 = (unsigned int *)malloc(sizeof(unsigned int) * (size + add))))
		return (1);
	i = 0;
	while (i < size)
	{
		tmp1[i] = index[0][i];
		tmp2[i] = index[1][i];
		i++;
	}
	free(index[0]);
	free(index[1]);
	index[0] = tmp1;
	index[1] = tmp2;
	return (0);
}

static unsigned int	ft_run_scan(const char *s, char c, unsigned int *nb_word,
		unsigned int **index)
{
	unsigned int		i;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			index[0][(*nb_word)++] = i;
		while (s[i] != c && s[i])
			i++;
		if (s[i] || s[i - 1] != c)
			index[1][*nb_word - 1] = (i - 1) - index[0][*nb_word - 1] + 1;
		if (*nb_word > 99)
			if (ft_realloc_index(index, *nb_word, 100))
				return (1);
	}
	return (0);
}

static unsigned int	**ft_scan_str(const char *s, char c, unsigned int *nb_word)
{
	unsigned int		**index;

	if (!(index = (unsigned int **)malloc(sizeof(unsigned int *) * 2)))
		return (NULL);
	if (!(index[0] = (unsigned int *)malloc(sizeof(unsigned int) * 100)))
		return (NULL);
	if (!(index[1] = (unsigned int *)malloc(sizeof(unsigned int) * 100)))
		return (NULL);
	*nb_word = 0;
	if (ft_run_scan(s, c, nb_word, index))
		return (NULL);
	return (index);
}

char				**ft_strsplit(char const *s, char c)
{
	char				**tab;
	unsigned int		**index;
	unsigned int		nb_word;
	unsigned int		i;

	if (!s)
		return (NULL);
	nb_word = 0;
	if (!(index = ft_scan_str(s, c, &nb_word)))
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	i = 0;
	while (i < nb_word)
	{
		tab[i] = ft_strsub(s, index[0][i], index[1][i]);
		i++;
	}
	tab[i] = 0;
	free(index[0]);
	free(index[1]);
	free(index);
	return (tab);
}
